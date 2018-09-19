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

size_t *addSize_tElement(size_t *list, size_t *size, size_t *capacity, size_t toAdd);
size_t removeDuplicate(char *line, size_t length, char *duplicate, size_t dupSize);

size_t removeDuplicate(char *line, size_t length, char *duplicate, size_t dupSize)
{
    size_t newSize = length - dupSize - 1;
    if (strcmp(duplicate, &line[0]) == 0)
    {
        for (size_t j = 0; j < length - dupSize - 1; j++)
        {
            line[j] = line[j + dupSize + 1];
        }
        return newSize;
    }

    for (size_t i = 0; i < length; i++)
    {
        if (line[i] == '\0' && i != length - 1)
        {
            if (strcmp(duplicate, &line[i + 1]) == 0)
            {
                for (size_t j = i; j < length - dupSize - 1; j++)
                {
                    line[j] = line[j + dupSize + 1];
                }
                return newSize;
            }
        }
    }
    return length;
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