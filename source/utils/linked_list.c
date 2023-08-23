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


struct cel* make_copy(struct cel* old)
{
    struct cel* i = NULL;
    struct cel* new = NULL;
    
    for (i = 0; i != NULL; i = i->next)
        add_elem(&new, i->num);
    
    return new;
}


int aux_copy_elems(struct cel* a, struct cel* b)
{
    if (a == NULL && b == NULL)
        return 0;
    else if(a == NULL || b == NULL)
        return 1;

    if (aux_copy_elems(a->next, b->next))
    {
        b->num = a->num;
        return 1;
    }

    return 0;
}

/*
 * A --> B
 */
int copy_elems(struct cel* a, struct cel* b)
{
    return aux_copy_elems(a, b);
}