#include "build_jwt.h"
#include <stdlib.h>
#include <string.h>

/**
 * Create an "HMAC auth" value for the "Authorization" header
 * which is just an encoded JWT using HMAC-SHA512
 * @param jwtSecret Secret key used to sign JWT
 * @param subject The "sub" grant of the JWT
 * @param jwtOutput The output, an encoded JWT
 */
int
create_hmac_jwt (const unsigned char *jwtSecret, char *subject, char **jwtOutput)
{
  int ret = 0;

  // Prepare timestamp in seconds
  time_t currentTimestamp = time (NULL);
  char *currentTimestampStr = malloc (1024);
  snprintf (currentTimestampStr, 1024, "%ld", currentTimestamp);

  jwt_t *jwt = NULL;
  jwt_new (&jwt);

  ret &= jwt_add_header (jwt, "typ", "JWT");
  ret &= jwt_add_header (jwt, "alg", "HS512");

  // Set claims
  ret &= jwt_add_grant (jwt, "iat", currentTimestampStr);
  ret &= jwt_add_grant (jwt, "sub", subject);

  // Set HMAC-SHA512 using secret key
  ret &= jwt_set_alg (jwt, JWT_ALG_HS512, jwtSecret, (int) strlen ((const char *) jwtSecret));

  // Encode and sign JWT
  *jwtOutput = jwt_encode_str (jwt);

  free (currentTimestampStr);
  jwt_free (jwt);

  return ret;
}
