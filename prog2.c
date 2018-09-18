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

    while (getline(&line, &lineLength, stdin) != -1)
    {
        words = strsplit(line, ", \t\n", &numWords);
    }
    for (size_t i = 0; i < numWords; i++)
    {
        printf("    word is: \"%s\"\n", words[i]);
        free(words[i]);
    }
    for(int i = 0; i < 3; i++) {
        removeDuplicate(line, strlen(line), words[i], strlen(words[i]));
    }
    printf(line);
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

    for (int k = i; k < length + 1; k++)
    {
        line[k] = line[k + dupSize];
    }
    return 0;
}

size_t *addSize_tElement(size_t *list, size_t *size, size_t *capacity, size_t toAdd)
{
    return 0;
}

char **strsplit(const char *str, const char *delim, size_t *numtokens)
{
    // copy the original string so that we don't overwrite parts of it
    // (don't do this if you don't need to keep the old line,
    // as this is less efficient)
    char *s = strdup(str);
    // these three variables are part of a very common idiom to
    // implement a dynamically-growing array
    size_t tokens_alloc = 1;
    size_t tokens_used = 0;
    char **tokens = calloc(tokens_alloc, sizeof(char *));
    char *token, *strtok_ctx;
    for (token = strtok_r(s, delim, &strtok_ctx);
         token != NULL;
         token = strtok_r(NULL, delim, &strtok_ctx))
    {
        // check if we need to allocate more space for tokens
        if (tokens_used == tokens_alloc)
        {
            tokens_alloc *= 2;
            tokens = realloc(tokens, tokens_alloc * sizeof(char *));
        }
        tokens[tokens_used++] = strdup(token);
    }
    // cleanup
    if (tokens_used == 0)
    {
        free(tokens);
        tokens = NULL;
    }
    else
    {
        tokens = realloc(tokens, tokens_used * sizeof(char *));
    }
    *numtokens = tokens_used;
    free(s);
    return tokens;
}