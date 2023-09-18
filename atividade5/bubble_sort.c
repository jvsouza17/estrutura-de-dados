#include "bubble_sort.h"
#include <string.h>

void bubbleSort(char **arr, int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                // Troca as palavras arr[j] e arr[j+1]
                char *temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}