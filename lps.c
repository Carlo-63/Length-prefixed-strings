#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "lps.h"

/*In questo file è presente l'implementazione di un sistema di lps (length-prefixed strings)
* Le stringhe create sono formate in questo modo:
*
*  +---+---+---+---+---+---*
*  | L | C | C | C | C |...|
*  +---+---+---+---+---+---*
*    ^               ^
*    |               |
* Length byte    Char byte

* Pertanto il primo byte della stringa viene occupato dalla lunghezza, gli altri da char
* In questo modo si limita il problema della presenza del carattere terminatore (\000) all'interno di una stringa
*/

char *lps_create(char *content, size_t length) {
    // Length deve essere <= 255 perchè un byte può contenere numeri fino al 255
    if (!content || length > 255) return NULL;

    char *buffer = (char*) malloc(1 + length);
    if (buffer == NULL) {
        return NULL;
    }

    buffer[0] = (char) length;

    memcpy(buffer + 1, content, length);

    return buffer;
}

void lps_print(char *str) {
    if (str == NULL) {
        return;
    }
    size_t length = (size_t) str[0];

    for (size_t i = 0; i < length; i++) {
        putchar(str[i+1]);
    }
    putchar('\n');
}

size_t lps_get_length(char *str) {
    return (size_t) str[0];
}

char *lps_concat(char *str1, char *str2) {
    if (!str1 || !str2) return NULL;

    size_t length1 = (size_t) str1[0];
    size_t length2 = (size_t) str2[0];
    size_t total_length = length1 + length2;

    if (total_length > 255) return NULL;

    char *new_string = (char*) malloc(1 + total_length);
    if (!new_string) return NULL;

    new_string[0] = (char) total_length;
    memcpy(new_string + 1, str1 + 1, length1);
    memcpy(new_string + 1 + length1, str2 + 1, length2);

    return new_string;
}

void lps_delete(char **str) {
    free(*str);
    *str = NULL;
}