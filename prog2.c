#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

size_t removeDuplicate(char *line, size_t length, char *duplicate, size_t dupSize);

size_t *addSize_tElement(size_t *list, size_t *size, size_t *capacity, size_t toAdd);

char **strsplit(const char *str, const char *delim, size_t *numtokens);

int main(int argc, char **argv)
{
    char *line = NULL;
    size_t lineLength = 0;
//    size_t n = 0;
    int arg;
    int x;
    size_t numWords = 0;
    if (argc == 1)
    {
        arg = 100;
    }
    else if (argc == 2)
    {
        arg = atoi(argv[1]);
    }
    else
    {
        fprintf(stderr, "Error: Too Many Arguments \n");
        return 0;
    }
    if (arg != 0)
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
    char **words = NULL;


    for (size_t i = 0; i < numWords; i++)
    {
        printf("    word is: \"%s\"\n", words[i]);
//        free(words[i]);
    }
    fprintf(stdout, "%s", line);
    size_t wordLength = 0;
    char* wordStart = line;
    while(*line != '\0' && *line != '\n') {
        while(*line != ' ') {
            wordLength++;
            line++;
        }
        removeDuplicate(line, strlen(line), wordStart, wordLength + 1);
        wordStart = wordStart + wordLength + 1;
    }

    fprintf(stdout, "line is: %s \n", line);
    if (words != NULL)
    {
        free(words);
    }

//    char* bucket = (char*)malloc(x * sizeof(char));
    int bucketSize = 2;
    for (int i = 0; i < bucketSize; i++)
    {
//        size_t numChars = strlen(buckets[i]) + 1;
//        fprintf(stdout, "Word %i: %s\n", i, words[i]);
    }
//    removeDuplicate(line, lineLength, )
    free(line);
    line = NULL;
    return 0;
}

size_t removeDuplicate(char *line, size_t length, char *duplicate, size_t dupSize)
{
    int i;
    int flag = 0;
    for(i = 0; i < length; i++) {
        if(line[i] == duplicate[0]) {
            int j;
            for(j = 0; j < dupSize; j++) {
                if(line[i+j] == duplicate[j]) {
		            fprintf(stdout, "Line of %d+%d = %c \n", i, j, line[i+j]);
                    flag = 1;
                } else {
                    flag = 0;
                }
                if(flag == 0) {
                    break;
                }
            }
            break;
        }
    }
    if(flag == 0) {
        return length;
    }
    // delete word
    size_t k;
    for (k = dupSize; k < length - dupSize; k++)
    {
        line[k] = line[k + dupSize];
    }
    return 0;
}

size_t *addSize_tElement(size_t *list, size_t *size, size_t *capacity, size_t toAdd)
{
    return 0;
}

