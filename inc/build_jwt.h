#ifndef PREREQ_H_
#define PREREQ_H_

#include <jwt.h>

int create_hmac_jwt (const unsigned char *jwtSecret, char *subject, char **jwt);

#endif // PREREQ_H_
