//Revise for DKU computer network class 2022 inhoinno
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define PORTNUM 1112        //MUST FIXME 1 : you change this port number and keep listen!
//Inhoinno : change it to your own packet
char packet[200];
uint64_t GetSize=0;
int main(void) {
    struct sockaddr_in socket_server, socket_client;
    struct hostent *host_entry;
    const char * your_server_addr="127.0.0.1";
    int sd, ns, ndx, msglen = sizeof(socket_client);
    int sa;
    
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
    * sin_port      : 
    */
    memset((char *)&socket_server, '\0', sizeof(socket_server));
    socket_server.sin_family = AF_INET;
    socket_server.sin_port = htons(PORTNUM);
    socket_server.sin_addr.s_addr = inet_addr(your_server_addr); 
    
    /* [3] Socket Connect */
    if (connect(sd, (struct sockaddr *)&socket_server, sizeof(socket_server))){
        perror("connect");
        exit(1);
    }
    /* [4] send/Recv*/
    GetSize = send(sd,(struct SendPacket*)&packet,sizeof(packet),0);
    fprintf(stderr, "Im Client, size:%ld packet:%s \n",GetSize,packet);
    close(sd);

      return 0;
  }
