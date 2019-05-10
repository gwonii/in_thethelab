#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>

void* on_read(void* arg) {
	int csock = (intptr_t) arg;
	char buf[128];
	int ret;
	while (1) {
		ret = read(csock, buf, sizeof buf);
		if (ret <= 0) break;
		write(1, buf, ret);
	}
	close(csock);
	return 0;
}


int main() {
	int sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		perror("socket");
		return 1;
	}

	struct sockaddr_in saddr = {0, };
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = inet_addr("192.168.0.3");
	saddr.sin_port = htons(5000);
	if (connect(sock, (struct sockaddr *)&saddr, sizeof saddr) == -1) {
		perror("connect");
		return 1;
	}
	
	intptr_t arg = sock;
	pthread_t thread;
	pthread_create(&thread, NULL, on_read, (void*)arg); 

	int ret;
	char buf[128];
	while (1) {
		ret = read(0, buf, sizeof buf);
		if (ret <= 0) break;
		write(sock, buf, ret);
	}
}
