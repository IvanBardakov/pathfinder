#include "../inc/libmx.h"

void mx_swapstr(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}
