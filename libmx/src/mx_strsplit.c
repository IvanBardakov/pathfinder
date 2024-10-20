#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (!s) 
        return NULL;

    int count_words = mx_count_words(s, c);
    char **result = (char **)malloc((count_words + 1) * sizeof(char *));
    if (!result) 
        return NULL;

    int i = 0, counter = 0;
    bool found_delimiter = false;

    while (s[i] != '\0') {
        
        if (s[i] == c) {
            if (found_delimiter) {
                
                for (int j = 0; j < counter; j++) {
                    free(result[j]);
                }
                free(result); 
                return NULL; 
            }
            found_delimiter = true; 
            i++;
            continue; 
        }
        
        found_delimiter = false; 

        int start = i; 
        while (s[i] != c && s[i] != '\0') {
            i++;
        }

        int len = i - start; 
        result[counter] = mx_strndup(&s[start], len); 

        
        if (!result[counter]) {
            
            for (int j = 0; j < counter; j++) {
                free(result[j]);
            }
            free(result); 
            return NULL; 
        }

        counter++; 
    }

    result[counter] = NULL; 
    return result; 
}
