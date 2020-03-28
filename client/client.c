/*************************************************************************
	> File Name: client.c
	> Author: wangshuai
	> Mail: ws1519704327@126.com
	> Created Time: 六  3/28 14:51:21 2020
 ************************************************************************/


#include "head.h"
#include "tcp_client.h"

int main(int argc, char **argv) {
    int sockfd;
    if (argc != 3) {
        fprintf(stderr, "Usage: %s ip port\n", argv[0]);
        return 1;
    }

    if ((sockfd = socket_connect(argv[1], atoi(argv[2]))) < 0) {
        perror("socket_connect");
        return 2;
    }

    return 0;
} 
