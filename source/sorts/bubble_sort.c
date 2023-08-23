#include "bubble_sort.h"

void bubble_sort(int array[], int len)
{
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
}


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


/*
 * Ao executar o arquivo ele verifica se o algoritmo está ordenando
 */
/*int main(int argc, char const *argv[])
{
    int len = 0;
    int* array = create_rand_array(&len);

    bubble_sort(array, len);

    array_is_ordered(array, len);
    
    return 0;
}*/
