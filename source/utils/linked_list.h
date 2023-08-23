#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct cel
{
    int num;
    struct cel* next;
} CEL;

/*
 * Serve pra inserir um numero na lista ligada
 */
void add_elem(struct cel** head, int num);

/*
 * Explode a lista sem vazar memória
 */
void free_list(struct cel* ptr);

/*
 * Remove elemento da lista com base na pos 
 */
bool remove_elem(struct cel** head, int index);

/*
 * Retorna o ptr da cel que tiver esse num
 * Caso nao tenha na lista esse num ele retornara NULL
 */
struct cel* search_for_num(struct cel* head, int num);

/*
 * Retorna o ptr da cel com o menor num
 */
struct cel* find_min(struct cel* head);

/*
 * Retorna o ptr da cel com o maior num
 */
struct cel* find_max(struct cel* head);

/*
 * Retorna uma copia da lista
 */
struct cel* make_copy(struct cel* old);

/*
 * Copia os elementos da lista a pra lista b
 * Caso seja de tamanhos diferente ele retornara 0
 * Caso de certo ele retornara 1
 * A --> B
 */
int copy_elems(struct cel* a, struct cel* b);

#endif /*LINKED_LIST_H*/