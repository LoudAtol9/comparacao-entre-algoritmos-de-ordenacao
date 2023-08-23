#include "selection_sort.h"

void selection_sort(int array[], int len)
{
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
}

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

/*
 * Ao executar o arquivo ele verifica se o algoritmo está ordenando
 */
/*int main(int argc, char const *argv[])
{
    int len = 0;
    int* array = create_rand_array(&len);

    selection_sort(array, len);

    array_is_ordered(array, len);
    
    return 0;
}*/
