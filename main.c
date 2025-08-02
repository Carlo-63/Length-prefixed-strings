#include <stdio.h>

#include "lps.h"

int main() {
    char *my_string = lps_create("Hel\000o World", 11);
    char *my_second_string = lps_create("My Second String", 16);
    
    lps_print(my_string);

    printf("Length: %ld\n", lps_get_length(my_string));

    char *concat_string = lps_concat(my_string, my_second_string);

    lps_print(concat_string);

    lps_delete(&my_string);

    lps_print(my_string);

    return 0;
}