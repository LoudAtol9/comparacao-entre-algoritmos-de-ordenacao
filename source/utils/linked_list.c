#include "linked_list.h"

void add_elem(struct cel** head, int num)
{
    struct cel** aux;
    struct cel* new;

    new = (struct cel*) malloc(sizeof(struct cel));
    new->num = num; 
    new->next = NULL;

    for (aux = head; (*aux) != NULL; aux = &((*aux)->next));

    *aux = new;
}

void free_list(struct cel* ptr)
{
    if (ptr != NULL)
    {
        free_list(ptr->next);
        free(ptr);
    }
}

bool remove_elem(struct cel** head, int index)
{
    int i = 0;
    struct cel** aux;
    struct cel* delete;

    for (aux = head; (*aux) != NULL && i < index; aux = &((*aux)->next))
        i++;
    
    if ((*aux) == NULL)
        return false;
    
    delete = *aux;
    *aux = (*aux)->next;

    free(delete);

    return true;
}


struct cel* search_for_num(struct cel* head, int num)
{
    struct cel* aux;

    for (aux = head; aux != NULL; aux = aux->next)
    {
        if (aux->num == num)
            return aux;
    }

    return NULL;
}


struct cel* find_min(struct cel* head)
{
    struct cel* min = head;
    struct cel* aux;

    for (aux = head->next; aux != NULL; aux = aux->next)
    {
        if (aux->num < min->num)
            min = aux;
    }

    return min;
}

struct cel* find_max(struct cel* head)
{
    struct cel* max = head;
    struct cel* aux;

    for (aux = head->next; aux != NULL; aux = aux->next)
    {
        if (aux->num > max->num)
            max = aux;
    }

    return max;
}

