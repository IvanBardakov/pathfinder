#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) return -1;
    int swapCount = 0;

    if (left < right) {
        int index = mx_partition(arr, left, right, &swapCount);
        if (left < index - 1) {
            swapCount += mx_quicksort(arr, left, index - 1);
        }
        if (index < right) {
            swapCount += mx_quicksort(arr, index, right);
        }
    }
    return swapCount;
}

