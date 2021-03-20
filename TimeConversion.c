#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

char* timeConversion(char* s) {
    int hour, min, sec;
    char ampm[3];
    sscanf(s, "%d:%d:%d%s", &hour, &min, &sec, ampm);
    ampm[2] = '\0';

    if (strcmp(ampm, "PM") == 0 && hour != 12) {
        hour += 12;
    } else if (strcmp(ampm, "AM") == 0) {
        hour = hour % 12;
    }

    char *str = malloc(9*sizeof(char));
    sprintf(str, "%02d:%02d:%02d", hour, min, sec);
    return(str);
}

int main()
{
    char* s = readline();

    char* result = timeConversion(s);
    printf("%s\n", result);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
