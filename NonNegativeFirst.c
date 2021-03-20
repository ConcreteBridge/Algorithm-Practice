
#include <stdio.h>
#include <stdlib.h>

void printArr(int* A, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void swap(int* A, int a, int b) {
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

int NonNegativeFirst(int* A, int lo, int hi) {
    int i = lo;
    int j = hi;
    int temp;
    while(i < j) {
        while(A[i] >= 0) { i++; }
        while(A[j] < 0) { j--; }
        swap(A, i, j);
    }
    swap(A, i, j);
    return j;
}

int main() {
    int A[10] = {2, 8, 3, -1, 6, -5, -4, 9, 7, 0};

    printArr(A, 10);
    NonNegativeFirst(A, 0, 9);
    printArr(A, 10);
    return 0;
}
