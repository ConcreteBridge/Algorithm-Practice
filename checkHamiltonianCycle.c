
#include <stdio.h>
#include <stdbool.h>

#define N   5

#define A   0
#define B   1
#define C   2
#define D   3
#define E   4

bool checkHamiltonianCycle(int G[][N], int a[N]) {
    for (int i = 0; i < N-1; i++) {
        if (G[a[i]][a[i+1]] != 1)
            return false;
    }
    if (G[a[0]][a[N-1]] != 1)
        return false;
    return true;
}

int main() {
    int G[N][N] = {
        {0,1,0,1,1},
        {1,0,1,0,1},
        {0,1,0,1,0},
        {1,0,1,0,1},
        {1,1,0,1,0}};
    
    int a[N] = {A,D,C,B,E};
    int b[N] = {A,D,B,C,E};
    int c[N] = {A,E,B,C,D};

    bool ans = checkHamiltonianCycle(G,a);
    puts(ans ? "true" : "false");
    ans = checkHamiltonianCycle(G,b);
    puts(ans ? "true" : "false");
}