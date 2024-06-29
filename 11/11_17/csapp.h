#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define	MAXLINE	 8192  /* Max text line length */

void Freeaddrinfo(struct addrinfo *res);

void Getnameinfo(const struct sockaddr *sa, socklen_t salen, char *host,
                 size_t hostlen, char *serv, size_t servlen, int flags);
