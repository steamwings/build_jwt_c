#include "build_jwt.h"
#include <stdlib.h>

int
main (const int argc, const char *const argv[])
{
  (void) argc;
  (void) argv;

  char *hmacKey = "secretkey00001";
  char *programUid = "1234";
  char *hmacAuth = NULL;

  int ret = create_hmac_jwt ((const unsigned char *) hmacKey, programUid, &hmacAuth);

  printf ("returned: %d\n", ret);
  printf ("hmacAuth: %s\n", hmacAuth);

  free (hmacAuth);

  return EXIT_SUCCESS;
}
