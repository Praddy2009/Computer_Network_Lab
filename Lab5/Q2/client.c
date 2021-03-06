/*
Client file
Client send integer array. Server sort it in ascending order and send back to client and the sorted array is printed in client side
*/

#include <stdio.h>
#include <sys/socket.h>     
#include <arpa/inet.h>      
#include <string.h>         
#include <stdlib.h>

int main(int argc,char *argv[]){
    int sock_fd,num[100],size,numrecv[100];
    struct sockaddr_in server;
    
    sock_fd=socket(AF_INET,SOCK_STREAM,0);                
    if(sock_fd == -1) {
        puts("Client socket creation FAILED\n");
        exit(1);
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");             
    server.sin_port = htons(6666);                      
    server.sin_family= AF_INET;

    if(connect(sock_fd, (struct sockaddr *) &server, sizeof(server))<0){
        puts("Connection failed");
        exit(1);
    }
    puts("Connection with server Successfull\n");
    printf("Input size of Array: ");
    scanf("%d",&size);
    

    num[0]=size;
    printf("Input elements of Array: ");
    for(int i=1;i<=size;i++){
        scanf("%d",&num[i]);
    }
    
    send(sock_fd,num,400,0);

    recv(sock_fd,numrecv,400,0);
    
    printf("Sorted Array: ");
    for(int i=1;i<=numrecv[0];i++){
       printf("%d, ",numrecv[i]);
    }
    printf("\n");
    
    return 0;
    
}