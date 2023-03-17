//Revise for DKU computer network class 2022 inhoinno
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define PORTNUM 31112        //MUST FIXME 1 : you change this port number and keep listen!
//Inhoinno : change it to your own packet
struct SendPacket{
    char ip[1000];
    char host[1000];
    char port[256];
};

int main(void) {
    const char * myhost ="127.0.0.1";
    struct sockaddr_in socket_server, socket_client;
    struct hostent *host_entry;
    int sd, ns, ndx, msglen = sizeof(socket_client);
    int sa;
    struct SendPacket sPacket;
    
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
    socket_server.sin_addr.s_addr = inet_addr(myhost);//INADDR_ANY 
    
    
    /* [3] Socket Bind */
    if (bind(sd, (struct sockaddr *)&socket_server, sizeof(socket_server))) {
        perror("bind");
            exit(1);
      }



      do{
    /* [4] Socket Listen */
    if (listen(sd, 5)) {
          perror("listen");
          exit(1);
      }
    /* [5] Accept : Now conntection has estabilished. extract socket_clientent's socket fd(=ns)*/
      if ((ns = accept(sd, (struct sockaddr *)&socket_client, &msglen))==-1){
          perror("accept");
         exit(1);
      }

    host_entry = gethostbyaddr((char*)&socket_client.sin_addr, 4, AF_INET);


     sprintf(sPacket.host, "Get From Server - My Host Name %s", host_entry->h_name);
     sprintf(sPacket.ip, "Get From Server - My IP Addresss %s", inet_ntoa(socket_client.sin_addr));
     sprintf(sPacket.port,"Get From Server - My Port Number %d", ntohs(socket_client.sin_port));
    
    /* [6] Send/Recv : send my packet*/
    if (send(ns,(struct SendPacket*)&sPacket,sizeof(sPacket),0)  == -1) {
          perror("send");
          exit(1);
      }
    

      fprintf(stderr, "Client Info - Host Name: %s\n", host_entry->h_name);
      fprintf(stderr, "Client Info - IP Address: %s\n",inet_ntoa(socket_client.sin_addr));
      fprintf(stderr, "Client Info - Port Number %d\n", ntohs(socket_client.sin_port));
      
      }while(1);

      close(sd);// Close server socket 
      return 0;
  }
