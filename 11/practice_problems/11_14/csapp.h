#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define	MAXLINE	 8192  /* Max text line length */

/* The error code set by various library functions.  */
extern int *__errno_location (void) __THROW __attribute_const__;
# define errno (*__errno_location ())

void Inet_ntop(int af, const void *src, char *dst, socklen_t size);

void unix_error(char *msg);

void Freeaddrinfo(struct addrinfo *res);

void Getnameinfo(const struct sockaddr *sa, socklen_t salen, char *host,
                 size_t hostlen, char *serv, size_t servlen, int flags);
