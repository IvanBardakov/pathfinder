#include "../inc/libmx.h"

long long mx_atoi(const char *str) {
    long long result = 0;
    int sign = 1;
    int i = 0;
    
    while (mx_isspace(str[i])) {
        i++;
    }
    
    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }

    if (str[i] == '0' && mx_isdigit(str[i + 1])) {
        return 0; 
    }

    while (str[i] != '\0') {
        if (mx_isdigit(str[i])) {
            
            if (result > (LLONG_MAX - (str[i] - '0')) / 10) {
                return (sign == 1) ? LLONG_MAX : LLONG_MIN; 
            }
            result = result * 10 + (str[i] - '0');
            i++;
        } else {
            return 0; 
        }
    }

    return sign * result;
}
