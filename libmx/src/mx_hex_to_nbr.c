#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex){
if (hex == NULL || hex[0] == '\0')
        return 0;

    unsigned long result = 0;
    int index = 0;

    while (hex[index] != '\0') {
        char currentChar = hex[index];
        if (mx_isdigit(currentChar))
            result = result * 16 + (currentChar - '0');
        else if ((currentChar >= 'a' && currentChar <= 'f') ||
            (currentChar >= 'A' && currentChar <= 'F')) {
            if (mx_islower(currentChar))
                result = result * 16 + (currentChar - 'a' + 10);
            else
                result = result * 16 + (currentChar - 'A' + 10);
        }
        else {
            return 0;
        }

        index++;
    }

    return result;
}
