
#include <stdio.h>
#include <stdlib.h>

int V = 5;
int E = 10;
int Length = 0;

typedef struct VertexDistance {
    char vertex;
    char previous;
} vertDist;

char* PathToTarget(vertDist *p, char target) {
    char *path = malloc(E * sizeof(char));
    char prev, vert = target;
    int i = 0;

    while ((p[i].vertex != vert) && (i < V)) {
        i++;
    }   // i is the index of the target in array p.

    while (vert != 's') {
        path[Length++] = vert;
        prev = p[i].previous;
        i = 0;
        while ((p[i].vertex != prev) && (i < V)) {
            i++;
        }   // i is the index of previous vertex.
        vert = p[i].vertex;
    }

    path[Length++] = 's';
    return path;
}

void PrintPathToTarget(vertDist *p, char target) {
    char prev, vert = target;
    int i = 0;

    while ((p[i].vertex != vert) && (i < V)) {
        i++;
    }   // i is the index of the target in array p.

    while (vert != 's') {
        printf("%c ", vert);
        prev = p[i].previous;
        i = 0;
        while ((p[i].vertex != prev) && (i < V)) {
            i++;
        }   // i is the index of previous vertex.
        vert = p[i].vertex;
    }
    printf("%c\n", 's');
}

int main() {
    vertDist *p = malloc(V * sizeof(vertDist));

    p[0].vertex = 's';
    p[0].previous = 's';

    p[1].vertex = 't';
    p[1].previous = 'y';

    p[2].vertex = 'x';
    p[2].previous = 't';

    p[3].vertex = 'y';
    p[3].previous = 's';

    p[4].vertex = 'z';
    p[4].previous = 'y';

    for (int i = 0; i < V; i++)
        printf("%c ", p[i].vertex);
    printf("\n");
    for (int i = 0; i < V; i++)
        printf("%c ", p[i].previous);
    printf("\n");

    char target = 'x';
    PrintPathToTarget(p, target);

    free(p);
}