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
//    size_t lineLength = 0;
//    size_t n = 0;
    int arg = 100;
    int bucketSize = 100;
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
            bucketSize = arg;
        }
    }
    fprintf(stdout, "The number is: %i\n", bucketSize);

    char** buckets = NULL;
    size_t numBuckets = 0;
    size_t* bucketSizes = 0;
    size_t* bucketSizesCapacity = 0;

    ssize_t lineLen = 0;
    size_t n = 0;
    while((lineLen = getline(&line, &n, stdin)) != -1)
    {
        if(lineLen > 0)
        {
            if(line[lineLen - 1] == '\n')
            {
                line[lineLen - 1] = '\0';
            }
        }
        fprintf(stdout, "%s \n", line);


        char* word;
        word = strtok(line, " \t");
        while (word != NULL)
        {
            printf ("%s\n", word);


            int inserted = 0;
            size_t wordLength = strlen(word);
            for(int i = 0; i < numBuckets; i++) {
                if(bucketSizes[i] + wordLength < bucketSize) {
                    //put in bucket
                    inserted = 1;
                    strcpy(buckets[i], word);
                }
            }

            if(inserted == 0) {
                buckets[numBuckets + 1] = (char*)malloc(bucketSize * sizeof(char));
                strcpy(buckets[numBuckets + 1], word);
                bucketSizesCapacity = addSize_tElement(bucketSizes, &wordLength, bucketSizesCapacity, wordLength);
                numBuckets++;
            }

            word = strtok (NULL, " \t");
        }



    }




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
    if (*size >= *capacity)
    {
        size_t newCapacity = (2 * (*capacity)) + 1;
        size_t *newList = (size_t *) malloc(newCapacity * sizeof(size_t));
        for (size_t i = 0; i < *size; i++)
        {
            newList[i] = list[i];
        }
        free(list);
        *capacity = newCapacity;
        newList[*size] = toAdd;
        (*size)++;
        return newList;
    }
    else
    {
        list[*size] = toAdd;
        (*size)++;
        return list;
    }
}
