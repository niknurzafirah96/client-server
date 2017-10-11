#include<unistd.h>
#include<arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
 
int main(int argc,char **argv)
{
    int sockfd,n;
    char sendline[100];
    char recvline[100];
    struct sockaddr_in servaddr;
 
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof servaddr);
 
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(7777);
 
    inet_pton(AF_INET,"192.168.40.132",&(servaddr.sin_addr));
 
    connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
 
    while(1)
    {
	printf ("Text to send: "); 
        bzero( sendline, 100);
        bzero( recvline, 100);
        fgets(sendline,100,stdin); /*stdin = 0 , for standard input */
  
	write(sockfd,sendline,strlen(sendline)+1);
        read(sockfd,recvline,100);
        printf ("Message from server: %s",recvline);
    }
 
}
