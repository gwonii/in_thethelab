
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>


int n = 0;
int clinet[1024];								
// 접속될 client들을 배열로 관리한다. 

/*
void *on_client(void *arg){
  
	int sock = (intptr_t)arg;
	char buf[128];								
	// 글자를 받을 배열
	
	int pos;
	// client의 현재위치 

  pos = n;
	client[n++] = sock;

}
*/

// 1. 소켓을 만들고 
// 2. 소켓에 주소를 넣고(바인드)
// 3. (리슨)
// 4. 사용자가 들어왔을 때 (어셉트) 해준다. 


int main() {

  int sd = socket(PF_INET, SOCK_STREAM, 0);
	// 소켓 생성 각자의 인자는 무엇을 의미하는가? 

	if (sd == -1) {
    perror("socket error");
		return 1;
	} // 소켓이 생성되지 않으면 -1값을 반환한다. 


	struct sockaddr_in saddr = {0,};
	// 소켓을 바인딩 하기 위해서는 구조체 내에 있는 정보에 값을 넣어줘야 한다. 
	// 구조체 내에 들어있는 변수 1. sin_family, 2. sin_addr.s_addr, 3. sin_port

	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = INADDR_ANY;
	saddr.sin_port = htons(5000);
	bind(sd, (struct sockaddr *)&saddr, sizeof(saddr));

	listen(sd, SOMAXCONN);

	struct sockaddr_in caddr = {0,};
	socklen_t caddrlen = sizeof caddr;


	while(1) {
    int sock = accept(sd, (struct sockaddr *)&caddr, &caddrlen);
		printf("%s \n", inet_ntoa(caddr.sin_addr));
	}
	close(sd);
}






