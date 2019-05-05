

#include <netinet/in.h>
//#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

// 주소 : 192.168.56.106

int main() {

				int sd = socket(PF_INET, SOCK_STREAM,0);
				if( sd == -1 ) {
								perror("socket error");
								return 1;
				}

				struct sockaddr_in saddr = {0,};
				saddr.sin_family = AF_INET;
				saddr.sin_addr.s_addr = INADDR_ANY;
				saddr.sin_port = htons(5000);

				bind(sd,(struct sockaddr*)&saddr, sizeof saddr);

				listen(sd, SOMAXCONN);

				struct sockaddr_in caddr = {0,};
				socklen_t caddrlen = sizeof caddr;

				while(1){

								int sock = accept(sd, (struct sockaddr *)&caddr, &caddrlen);
								printf("%s\n", inet_ntoa(caddr.sin_addr));


								while(1) {
												char buf[128];
												int ret = read(sock, buf, sizeof buf);
												if (ret <= 0) {
																//break;
												}

												write(sock, buf, ret);
								}
								close(sock);
				}
				//close(sd);
}

