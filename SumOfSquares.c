
#include <stdio.h>
#include <stdlib.h>

void printArr(int* A, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", *(A + i));
    }
    printf("\n");
}

int SumOfSquares(int *A, int n) {
    if (n == 0) return A[0] * A[0];
    return SumOfSquares(A, n-1) + A[n]*A[n];
}

int main() {
    int A[10] = {0, 3, 5, 7, 9, 12, 15, 18, 21, 24};

    printArr(A, 10);
    int ans = SumOfSquares(A, 9);
    printf("%d\n", ans);

    return 0;
}
