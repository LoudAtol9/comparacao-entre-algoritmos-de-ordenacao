#include "asserts_for_sorting.h"

bool aux_array_is_ordered(int* array, int len)
{
    int i;

    for (i = 0; i < len - 1; i++)
    {
        if (array[i] > array[i + 1])
            return false;
    }
}

void array_is_ordered(int array[], int len)
{
    assert(aux_is_ordered(array, len));
}


bool aux_list_is_ordered(struct cel* head)
{
    struct cel* aux;

    for (aux = head; aux->next != NULL; aux = aux->next)
    {
        if (aux->num > aux->next->num)
            return false;
    }
}

void list_is_ordered(struct cel* head)
{
    assert(aux_list_is_ordered(head));
}