#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

size_t removeDuplicate(char* line, size_t length, char* duplicate, size_t dupSize);
size_t* addSize_tElement(size_t* list, size_t* size, size_t* capacity, size_t toAdd);

int main(int argc, char **argv) {
    char* line = NULL;
    ssize_t lineLength = 0;
    size_t n = 0;
    int arg ;
    int x;
    if(argc == 1) {
        arg = 100;
    } else if(argc == 2) {
        arg = atoi(argv[1]);
    } else
    {
        fprintf(stderr, "Error: Too Many Arguments \n");
        return 0;
    }
    if(arg != 0)
    {
        if (arg < 20 || arg > 100000)
        {
            fprintf(stderr, "Error: Invalid Argument Size \n");
            return 0;
        }
        else
        {
            x = arg;
        }
    }
    fprintf(stdout, "The number is: %i\n", x);
    while ((lineLength = getline(&line, &n, stdin)) != -1) {
        if(lineLength > 0)
        {
//            if(line[lineLength - 1] == '\n')
//            {
//                line[lineLength - 1] = '\0';
//            }
        }
    }

    char* bucket = (char*)malloc(x * sizeof(char));
    strcpy(bucket, line);
    fprintf(stdout, "The line is: %s\n", bucket);
//    removeDuplicate(line, lineLength, )
    free(line);
    line = NULL;
	return 0;
}

size_t removeDuplicate(char* line, size_t length, char* duplicate, size_t dupSize) {

    return 0;
}

size_t* addSize_tElement(size_t* list, size_t* size, size_t* capacity, size_t toAdd) {
    return 0;
}