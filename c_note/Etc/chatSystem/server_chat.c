#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

int n = 0;
int clients[1024]; // 여러 스레드가 공유하는 자원 -> 뮤텍스를 써야 한다!
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *on_client(void * arg) {
	int sock = (intptr_t) arg;
	char buf[128];
	int pos;
	
	pthread_mutex_lock(&mutex);
	pos = n;
	clients[n++] = sock;	
	pthread_mutex_unlock(&mutex);

	while (1) {
		int ret = read(sock, buf, sizeof buf);
		if (ret <= 0) {
			break;
		}
		int i;
		pthread_mutex_lock(&mutex);
		for (i = 0; i < n; ++i) {
			write(clients[i], buf, ret);	
		}
		pthread_mutex_unlock(&mutex);
	}
	
	pthread_mutex_lock(&mutex);
	clients[pos] = clients[n-1];
	n--;
	pthread_mutex_unlock(&mutex);
	close(sock);
	return 0;
}
int main() {
	int sd = socket(PF_INET, SOCK_STREAM, 0);
	if (sd == -1) {
		perror("socket");
		return 1;
	}

	struct sockaddr_in saddr = {0, };
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = INADDR_ANY;
	saddr.sin_port = htons(5000);
	bind(sd, (struct sockaddr *)&saddr, sizeof(saddr));

	listen(sd, SOMAXCONN);

	struct sockaddr_in caddr = {0, };
	socklen_t caddrlen = sizeof caddr;

	while (1) {
		int sock = accept(sd, (struct sockaddr *)&caddr, &caddrlen);
		printf("%s\n", inet_ntoa(caddr.sin_addr));

		pthread_t thread;
		intptr_t arg = sock; // 인트타입을 포인터타입으로 담을 때. -> 8바이트임
		pthread_create(&thread, NULL, on_client, (void*) arg);
		pthread_detach(thread); // 스레드 띠어내서 메모리 누수를 막는다.
	}
	close(sd);
}

