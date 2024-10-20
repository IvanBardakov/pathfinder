#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count)
{
    int left = 0;
    int right = size - 1;
    *count = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        (*count)++;

        int cmp_result = mx_strcmp(arr[mid], s);

        if (cmp_result == 0)
        {
            return mid;
        }
        else if (cmp_result < 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    *count = 0;
    return -1;
}
