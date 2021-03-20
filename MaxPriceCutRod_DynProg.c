
#include <stdio.h>

#define M   3
#define N   5

int max(int a, int b) {
    if(a > b)
        return a;
    return b;
}

int main() {
    int i, j, F[M + 1];
    int p[N] = {1, 3, 1, 14, 1};

    F[0] = 0;
    for (i = 1; i < M + 1; i++) {
        F[i] = 0;
        for (j = 1; j <= i; j++) {
            F[i] = max(F[i], F[i-j] + p[j-1]);
        }
    }
    printf("max price: %d\n", F[M]);

    printf("p: ");
    for (i = 0; i < N; i++)
        printf("%d ", p[i]);
    printf("\n");

    printf("F: ");
    for (i = 0; i < M-1; i++)
        printf("%d ", F[i]);
    printf("\n");
}