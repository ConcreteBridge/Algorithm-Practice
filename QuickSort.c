
#include <stdio.h>
#include <stdlib.h>

void printArr(int* A, int length, int lt, int gt) {
    for (int i = 0; i < length; i++) {
        if(i == lt)
            printf(" L");
        else if(i == gt)
            printf(" G");
        else   
            printf("  ");
        printf("%d", A[i]);
    }
    printf("\n");
}

void swap(int* A, int a, int b) {
    if(a == b) return;
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

int LomutoPartition(int *arr, int l, int r, int *lt, int *gt) {
    int P = arr[l];
    (*lt) = l;
    (*gt) = l;
    for (int i = l+1; i <= r; i++) {
        if (arr[i] < P) {
            (*lt)++;
            (*gt)++;
            swap(arr, *gt, *lt);
            swap(arr, *lt, i);
        }
        if (arr[i] == P) {
            (*gt)++;
            swap(arr, *gt, i);
        }
    }
    swap(arr, *lt, l);
}

void QuickSort(int *arr, int l, int r) {
    int lt, gt;
    if (l < r) {
        LomutoPartition(arr, l, r, &lt, &gt);
        printArr(arr, 10, lt, gt);
        QuickSort(arr, l, lt-1);
        QuickSort(arr, gt+1, r);
    }
}

int main() {
    int A[10] = {9, 2, 7, 6, 5, 4, 3, 2, 1, 0};

    printArr(A, 10, -1, -1);
    QuickSort(A, 0, 9);
    printArr(A, 10, -1, -1);

    return 0;
}
