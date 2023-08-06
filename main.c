#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>
#include <sys/types.h>
#include <WS2tcpip.h>

#pragma comment(lib, "wsock32.lib")

int main(int argc, char** argv)
{
    int port = 5501;
    int sockfd;
    struct sockaddr_in myaddr, remoteAddr;
    char buffer[1024];
    socklen_t addr_size;
    //              ipv4    udp datagram
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    memset(&myaddr, '\0', sizeof(myaddr));
    myaddr.sin_family      = AF_INET;
    myaddr.sin_port        = htons(port);
    myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(sockfd, (struct sockaddr*)&myaddr, sizeof(myaddr));
    addr_size = sizeof(remoteAddr);
    recv(sockfd, buffer, 1024, 0);
    printf("Got data from %s", buffer);
    return 0;
}