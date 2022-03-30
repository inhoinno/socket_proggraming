//Revise for DKU computer network class 2022 in    hoinno
//Origin Source : https://github.com/ujusy/C_So    cket_/blob/master/client.c
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#define PORTNUM 31112 //MUST FIXME 1 : you change this port number and keep listen!

 struct SendPacket{
    char ip[1000];
    char host[1000];
    char port[256];
};

int main(void){
    const char * your_server_ipaddr = "127.0.0.1";//"xxx.xxx.xxx.xxx";    //MUST FIXME 2 : you should chage addr to your server ip
    int sd;
    struct sockaddr_in socket_server;
    struct SendPacket sPacket;
    int GetSize;
    char suBuffer[1000];

        /* [1] create socket by calling socket system call
        <sys/types.h> <sys/socket.h>
        int socket(int domain, int type, int protocol)
 
        @return
        file descriptor of socket (sd)
 
        @param
        int domain  : which protocol family? (IPv4 : AF_INET)
        int type    : which protocol type?   (TCP : SOCK_STREAM, UDP : SOCK_DGRAM, Userdefine : SOCK_RAW
        int protocol: look http://www.geeksforgeeks.org/socket-programming-cc/
        */

    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }


    /** [2] setsockopt
    sin: sockaddr_in
    * sin_family    : Address Family (AF_INET : IPv4)
    * sin_addr      : 32bit IP Address
    * sin_port      : port to use
    */

    memset((char *)&socket_server, '\0', sizeof(socket_server));
    socket_server.sin_family = AF_INET;
    socket_server.sin_port = htons(PORTNUM);
    socket_server.sin_addr.s_addr = inet_addr(your_server_ipaddr);

    /* [3] Socket Connect */
    if (connect(sd, (struct sockaddr *)&socket_server, sizeof(socket_server))) {
        perror("connect");
        exit(1);
    }
    /* [4] send/Recv*/
    GetSize = recv(sd,(struct SendPacket*)&sPacket,sizeof(sPacket),0);
    fprintf(stderr, "Im Client, host:%s \n",sPacket.host);
    fprintf(stderr, "Im Client, ip  :%s \n",sPacket.ip);
    fprintf(stderr, "Im Clientm port:%s \n",sPacket.port);
    close(sd);


    return 0;
}
