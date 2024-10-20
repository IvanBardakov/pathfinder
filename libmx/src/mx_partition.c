#include "../inc/libmx.h"

int mx_partition(char **arr, int left, int right, int *swapCount) {
    int mid = left + (right - left) / 2;
    char *pivot = arr[mid];
    int i = left;
    int j = right;

    while (i <= j) {
        while (mx_strlen(arr[i]) < mx_strlen(pivot)) {
            i++;
        }
        while (mx_strlen(arr[j]) > mx_strlen(pivot)) {
            j--;
        }
        if (i <= j) {
            if (mx_strlen(arr[i]) != mx_strlen(arr[j])) {
                mx_swapstr(&arr[i], &arr[j]);
                (*swapCount)++;
            }
            i++;
            j--;
        }
    }
    return i;
}
