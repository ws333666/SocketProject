/*************************************************************************
	> File Name: client.c
	> Author: wangshuai
	> Mail: ws1519704327@126.com
	> Created Time: 六  3/28 14:51:21 2020
 ************************************************************************/


#include "head.h"
#include "tcp_client.h"
#include "common.h"

int main(int argc, char **argv) {
    char msg[512] = {0};
    int sockfd;
    if (argc != 4) {
        fprintf(stderr, "Usage: %s ip port\n", argv[0]);
        return 1;
    }

    if ((sockfd = socket_connect_timeout(argv[1], atoi(argv[2]), atoi(argv[3]))) < 0) {
        perror("socket_connect");
        return 2;
    }
    make_nonblock_ioctl(sockfd);
    recv(sockfd, msg, 512, 0);
    printf("recv : %s\n", msg);
    close(sockfd);
    return 0;
} 
