#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv) {
    char* line = NULL;
    ssize_t lineLength = 0;
    size_t n = 0;
    int arg = atoi(argv[1]);
    int x;
    if(argc != 2) {
        fprintf(stderr, "Error: Too Many Arguments \n");
    } else if(arg < 20 || arg > 100000) {
        fprintf(stderr, "Error: Invalid Argument Size \n");
        x = 0;
    } else {
        x = arg;
    }
    fprintf(stdout, "The number is: %i\n", x);
    while ((lineLength = getline(&line, &n, stdin)) != -1) {
        if (lineLength > 0)
        {
            if (line[lineLength - 1] == '\n')
            {
                line[lineLength - 1] = '\0';
            }
        }
    }
    fprintf(stdout, "The line is: %s \n", line);
    free(line);
    line = NULL;
	return 0;
}