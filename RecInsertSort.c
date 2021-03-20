
#include <stdio.h>
#include <stdlib.h>

void printArr(int* A, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", *(A + i));
    }
    printf("\n");
}

void InsertionSort(int* A, int lo, int hi) {
    if (lo == hi)
        return;
    InsertionSort(A, lo, hi - 1);
    int i = hi - 1;
    int temp = A[hi];
    while (i >= 0 && A[i] > temp) {
        A[i + 1] = A[i];
        i = i - 1;
    }
    A[i + 1] = temp;
    return;
}

int main() {
    int A[10] = {6, 0, 5, 8, 9, 4, 7, 3, 2, 1};

    printArr(A, 10);
    InsertionSort(A, 0, 9);
    printArr(A, 10);
    return 0;
}
