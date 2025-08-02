#include <sys/types.h>

#ifndef lps_H
#define lps_H

char *lps_create(char*, size_t);
void lps_print(char*);
size_t lps_get_length(char*);
char *lps_concat(char *str1, char *str2);
void lps_delete(char**);

#endif