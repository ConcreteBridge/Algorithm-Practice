
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArr(int* A, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", *(A + i));
    }
    printf("\n");
}

bool OffByOne(int *arr, int n) {
    for (int i = 0; i <= n-2; i++) {
        for (int j = i+1; j <= n-1; j++) {
            if (arr[i] == arr[j]+1 || arr[i] == arr[j]-1)
                return true;
        }
    }
    return false;
}

int main() {
    int A[10] = {0, 3, 5, 7, 9, 12, 15, 18, 21, 24};
    int B[10] = {0, 3, 4, 7, 9, 12, 15, 18, 21, 24};

    printArr(A, 10);
    bool ans = OffByOne(A, 10);
    printf("%s\n", ans ? "true" : "false");

    printArr(B, 10);
    ans = OffByOne(B, 10);
    printf("%s\n", ans ? "true" : "false");

    return 0;
}
