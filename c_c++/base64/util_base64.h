/*util_base64.h*/
#ifndef UTIL_BASE64_H
#define UTIL_BASE64_H

int base64_encode(unsigned char *in, unsigned char *out, int out_len);
int base64_decode(unsigned char *in, unsigned char *out, int out_len);

#endif
