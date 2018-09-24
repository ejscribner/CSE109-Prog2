/*
    CSE 109: Fall 2018
    Elliot Scribner
    ejs320
    Program allocates buckets of memory to put words into and prints the result
    Program #2
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

size_t removeDuplicate(char *line, size_t length, char *duplicate, size_t dupSize);

size_t *addSize_tElement(size_t *list, size_t *size, size_t *capacity, size_t toAdd);

size_t occuranceCount(char *line, size_t length, char *duplicate, size_t dupSize);

int main(int argc, char **argv)
{
    char* line = NULL;
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
    char** buckets = (char**)malloc(20 * sizeof(char*));
    size_t numBuckets = 0;
    size_t* bucketSizes = (size_t*)malloc(1* sizeof(size_t));
    size_t bucketSizesCapacity = 1;

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

        char* word;
        word = strtok(line, " \t");
        while (word != NULL)
        {
            int inserted = 0;
            size_t wordLength = strlen(word);
            if(wordLength > bucketSize - 1) {
                break;
            }
            for(int i = 0; i < numBuckets; i++) {
                if(bucketSizes[i] + wordLength + 1 < bucketSize - 1) {
                    //put in bucket
                    inserted = 1;
                    size_t startIndex = bucketSizes[i];
                    for(size_t j = startIndex; j < startIndex + wordLength; j++) {
                        buckets[i][j] = word[j - startIndex];
                    }
                    bucketSizes[i] += wordLength + 1;
                    buckets[i][startIndex + wordLength] = ' ';
                }
            }
            if(inserted == 0) {
                buckets[numBuckets] = (char*)malloc(bucketSize * sizeof(char));
                strcpy(buckets[numBuckets], word);
                buckets[numBuckets][wordLength] = ' ';
                size_t tempNumBuckets = numBuckets;
                bucketSizes = addSize_tElement(bucketSizes, &tempNumBuckets, &bucketSizesCapacity, wordLength + 1);
                numBuckets++;
            }

            word = strtok (NULL, " \t");
        }
    }


    //Call remove duplicate

    for(int i = 0; i < numBuckets; i++) {
        char* word = (char*)malloc(bucketSize * sizeof(char));
        size_t wordLength = 0;
        for(int j = 0; j < bucketSizes[i]; j++) {
            char letter = buckets[i][j];
            if(!isspace(letter)) {
                word[wordLength] = letter;
                wordLength++;
            } else {
                //word found to be removed
                for(int k = i; k < numBuckets; k++) {
                    size_t occurance = occuranceCount(buckets[k], bucketSizes[k], word, wordLength);
                    if(occurance > 1 && k == i) {
                        size_t newCurrentSize = removeDuplicate(buckets[i], bucketSizes[i], word, wordLength);
                        newCurrentSize = removeDuplicate(buckets[i], newCurrentSize, word, wordLength);
                        j -= bucketSizes[i] - newCurrentSize;
                        bucketSizes[i] = newCurrentSize;
                        break;
                    } else if (occurance > 0 && k != i) {
                        //removing word from current bucket
                        size_t newCurrentSize = removeDuplicate(buckets[i], bucketSizes[i], word, wordLength);
                        j -= bucketSizes[i] - newCurrentSize;
                        bucketSizes[i] = newCurrentSize;
                        bucketSizes[k] = removeDuplicate(buckets[k], bucketSizes[k], word, wordLength);
                        break;
                    }
                }

                wordLength = 0;


            }
        }
    }



    for(int j = 0; j < numBuckets; j++) {
        fprintf(stdout, "%*zu: %s \n", 6, bucketSizes[j], buckets[j]);
        free(buckets[j]);
        buckets[j] = NULL;
    }
    free(buckets);
    buckets = NULL;

    free(line);
    line = NULL;
    return 0;
}

size_t removeDuplicate(char *line, size_t length, char *duplicate, size_t dupSize)
{
    //find duplicate
    int duplicateIndex = 0;
    int dupStart = -1;
    for(int i = 0; i < length; i++) {
        if(duplicateIndex == dupSize - 1) {
            break;
        }
        if(line[i] == duplicate[duplicateIndex]) {
            if(duplicateIndex == 0) {
                dupStart = i;
            }

            duplicateIndex++;
        } else {
            duplicateIndex = 0;
            dupStart = -1;
        }
    }

    if(dupStart == -1) {
        return length;
    }


    //remove duplicate
    for(int j = dupStart; j < length; j++) {

        line[j] = line[j + dupSize + 1];
    }
    return length - dupSize - 1;
}

size_t occuranceCount(char *line, size_t length, char *duplicate, size_t dupSize)
{
    size_t duplicateIndex = 0;
    size_t numDups = 0;
    for(int i = 0; i < length; i++) {
        if(duplicateIndex == dupSize - 1) {
            numDups++;
            duplicateIndex = 0;
        }
        if(line[i] == duplicate[duplicateIndex]) {
            duplicateIndex++;
        } else {
            duplicateIndex = 0;
        }
    }
    return numDups;
}

size_t *addSize_tElement(size_t *list, size_t *size, size_t *capacity, size_t toAdd)
{
    if (*size >= *capacity)
    {
        size_t newCapacity = (2 * (*capacity)) + 1;
        size_t *newList = (size_t *) malloc(newCapacity * sizeof(size_t));
        for (int i = 0; i < *size; i++)
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
