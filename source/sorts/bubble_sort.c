#include "bubble_sort.h"

uint64_t bubble_sort(int array[], int len)
{
    struct timeval start;
    struct timeval stop;

    gettimeofday(&start, NULL);

    /*Começo da Ordenação*/
    int i;
    int buffer;

    bool swap = true;

    while (swap)
    {
        swap = false;

        for (i = 0; i < len - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap = true;

                buffer = array[i];
                array[i] = array[i + 1];
                array[i + 1] = buffer;
            }
        }
    }
    /*Fim da Ordenação*/

    gettimeofday(&stop, NULL);

    return deltatime_to_uint64(start, stop);
}

/*
void din_bubble_sort(struct cel** head)
{
    bool swap = true;

    struct cel** i = head;
    struct cel** aux;
    struct cel* buffer;

    while (swap)
    {
        swap = false;

        for (i = head; (*i) != NULL; i = &((*i)->next))
        {
            if ((*i)->num > (*i)->next->num)
            {
                swap = true;

                aux = &((*i)->next);

                buffer = (*i);
                buffer->next = (*aux)->next;
                (*aux)->next = (*i)->next;
                (*i) = (*aux);
                (*aux) = buffer;
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

    printf("%" PRIu64, bubble_sort(arr, len));
}
