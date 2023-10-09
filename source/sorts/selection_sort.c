#include "selection_sort.h"

uint64_t selection_sort(int array[], int len)
{
    struct timeval start;
    struct timeval stop;

    gettimeofday(&start, NULL);

    /*Começo da Ordenação*/
    int i;
    int y;

    int min;
    int buffer;

    for (i = 0; i < len; i++)
    {
        min = i;

        for (y = i + 1; y < len; y++)
        {
            if (array[min] > array[y])
                min = y;
        }

        if (i != min)
        {
            buffer = array[i];
            array[i] = array[min];
            array[min] = buffer;
        } 
    }
    /*Fim da Ordenação*/

    gettimeofday(&stop, NULL);

    return deltatime_to_uint64(start, stop);

}

/*
void din_selection_sort(struct cel** head)
{
    struct cel** i;
    struct cel** y;

    struct cel** min;
    struct cel* buffer;

    for (i = head; (*i) != NULL; i = &((*i)->next))
    {

        min = i; 

        for (y = (*i)->next; (*y) != NULL; y = &((*y)->next))
        {
            if ((*min)->num > (*y)->num)
                min = y;
        }

        if (i != min)
        {
            buffer = (*i);
            buffer->next = (*y)->next;
            (*y)->next = (*i)->next;
            (*i) = (*y);
            (*y) = buffer;
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

    printf("%" PRIu64, selection_sort(arr, len));
}
