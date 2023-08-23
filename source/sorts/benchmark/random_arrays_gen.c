#include "random_arrays_gen.h"

/*
 * Recebe um tamanho e cria um array com elementos aleatórios
 * num intervalo de 0 a 10.000
 * 
 * Caso o tamanho seja zero, ele vai sortear o tamanho
 */
int* create_rand_array(int* len)
{
    int i;
    int* array;

    srand(time(0));

    if (*len == 0)
    {
        *len = (rand() % 10000);
    }

    array = (int*) malloc(sizeof(int) * (*len));

    for (i = 0; i < *len; i++)
        array[i] = (rand() % 10000);
    
    return array;
}

/*
 * Recebe um tamanho e cria uma lista com elementos aleatórios
 * num intervalo de 0 a 10.000
 * 
 * Caso o tamanho seja zero, ele vai sortear a qnt de elementos
 */
struct cel* creat_rand_list(int len)
{
    int i;
    struct cel* list = NULL;

    srand(time(0));

    if (len == 0)
    {
        len = (rand() % 10000);
    }

    for (i = 0; i < len; i++)
        add_elem(list, (rand() % 10000));
    
    return list;
}