#include "insertion_sort.h"

uint64_t insertion_sort(int array[], int len)
{
    struct timeval start;
    struct timeval stop;

    gettimeofday(&start, NULL);

    /*Começo da Ordenação*/
    int i;
    int j;
    int key;

    for (i = 0; i < len; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    /*Fim da Ordenação*/

    gettimeofday(&stop, NULL);

    return deltatime_to_uint64(start, stop);
}

/*
void din_insertion_sort(struct cel** head)
{
    struct cel** i;
    struct cel** j;
    struct cel* buffer;

    for (i = head; (*i) != NULL; i = &((*i)->next))
    {
        for (j = head; (*j) != (*i); j = &((*j)->next))
        {
            if ((*j)->num < (*i)->num)
            {
                buffer = (*j);
                buffer->next = i;
                (*j) = (*j)->next;
                (*i) = buffer;
            }
        }
    }
}
*/

int main(int argc, char const *argv[])
{
    int i;
    int len;
    int* arr;

    if (argc < 2)
        return 0;

    len = argc - 1;
    arr = (int*) malloc(sizeof(int) * len);
    
    for (i = 0; i < len; i++)
        arr[i] = atoi(argv[i + 1]);

    printf("%" PRIu64, insertion_sort(arr, len));
}
