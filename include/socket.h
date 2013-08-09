#ifndef SOCKET_H
#define SOCKET_H

#include <sys/types.h>
#include <openssl/bio.h>

#define IRCLEN 512
#define SSLSTORE "/etc/ssl/certs/ca-certificates.crt"

// Returns a valid socket descriptor or -1 if it fails
BIO *sock_connect(const char *address, const char *port);

// Write n bytes from buf without altering them (raw)
// Returns the length specified (n) or -1 if it fails
ssize_t sock_write(BIO *sock, const char *buf, size_t n);

// Build a valid IRC line (with \r\n terminators) and store it null terminated in line_buff
// Returns line length. Characters after the IRC message terminators are left untouched for the next call
// It uses sock_readbyte() internally which mantain it's own buffer so it doesn't call read() for every single byte
ssize_t sock_readline(BIO *sock, char *line_buf, size_t len);

#endif
