#include "insertion_sort.h"

void insertion_sort(int array[], int len)
{
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
}

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

/*
 * Ao executar o arquivo ele verifica se o algoritmo está ordenando
 */
/*int main(int argc, char const *argv[])
{
    int len = 0;
    int* array = create_rand_array(&len);

    insertion_sort(array, len);

    array_is_ordered(array, len);
    
    return 0;
}*/
