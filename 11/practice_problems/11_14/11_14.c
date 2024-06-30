/*
Practice problem 11.

The getaddrinfo and getnameinfo functions subsume the functionality of
inet_pton and inet_ntop, respectively, and they provide a higher-level
of abstraction that is independent of any particular address
format. To convince yourself how handy this is, write a version of
HOSTINFO ( Figure 1 1 .17) that uses inet_n top instead of getnameinfo
to convert each socket address to a dotted-decimal address string.
*/

#include <netinet/in.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "csapp.h"
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    struct addrinfo *p, *listp, hints;
    char buf[MAXLINE];
    int rc, flags;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <domain name>\n", argv[0]);
        exit(0);
    }

    /* Get list of addrinfo records */
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET; /* IPv4 only */
    hints.ai_socktype = SOCK_STREAM; /* Connections only */
    rc = getaddrinfo(argv[1], NULL, &hints, &listp);
    if (rc != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rc));
        exit(1);
    }

    /* Walk the list and display each IP address */
    flags = NI_NUMERICHOST; /* Display address string instead of domain name */
    for (p = listp; p; p = p->ai_next) {
        // Code we want to replace #############################################
        //
        // Getnameinfo(p->ai_addr, p->ai_addrlen, buf, MAXLINE, NULL, 0, flags);
        // printf("%s\n", buf);
        // #####################################################################

        // Generic socket address structure
        struct sockaddr *socket_address = p->ai_addr;

        // Let's cast it to an internet socket address structure
        struct sockaddr_in *ip_socket_address = (struct sockaddr_in*) socket_address;

        // address structure
        struct in_addr address_structure = ip_socket_address->sin_addr;
        // address in network byte order (big endian)
        uint32_t address = address_structure.s_addr;

        // We can now use inet_ntop which converts a binary IP address
        // in network byte order to the corresponding dotted-decimal
        // representation
        const char *res = inet_ntop(AF_INET, &address, buf, MAXLINE);
        if (!res) {
            printf("inet_ntop error");
            exit(1);
        }

        // print dotted-decimal representation
        printf("%s\n", buf);
    }

    /* clean up */
    Freeaddrinfo(listp);

    exit(0);
}
