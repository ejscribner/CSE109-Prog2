size_t* addSize_tElement(size_t* list, size_t* size, size_t* capacity, size_t toAdd);
size_t removeDuplicate(char* line, size_t length, char* duplicate, size_t dupSize);


int main(int argc, char **argv)
{

}

size_t removeDuplicate(char* line, size_t length, char* duplicate, size_t dupSize)
{
    size_t newSize = length - dupSize - 1;
    size_t j = 0;

    if(strcmp(duplicate, &line[0]) == 0)
    {
        while(j < length - dupSize - 1)
        {
            line[j] = line[j + dupSize + 1];
            j++;
        }
        return newSize;
    }
    size_t i = 0;
    while(i < length)
    {
        if(line[i] == '\0' && i != length - 1)
        {
            if(strcmp(duplicate, &line[i + 1]) == 0)
            {
                size_t j = i;
                while(j < length - dupSize - 1)
                {
                    line[j] = line[j + dupSize + 1];
                    j++;
                }
                return newSize;
            }
        }
    }
    return length;
}

size_t* addSize_tElement(size_t* list, size_t* size, size_t* capacity, size_t toAdd)
{
    if(*size >= *capacity)
    {
        size_t newCapacity = (2 * (*capacity)) + 1;
        size_t* newList = (size_t*)malloc(newCapacity * sizeof(size_t));
        size_t i = 0;
        while(i < *size)
        {
            newList[i] = list[i];
            i++;
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