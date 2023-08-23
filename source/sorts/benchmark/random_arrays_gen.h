#ifndef RANDOM_ARRAYS_GEN_H
#define RANDOM_ARRAYS_GEN_H

#include <stdlib.h>
#include <time.h>

#include "../../utils/linked_list.h"

/*
 * Recebe um tamanho e cria um array com elementos aleatórios
 * num intervalo de 0 a 10.000
 * 
 * Caso o tamanho seja zero, ele vai sortear o tamanho
 */
int* create_rand_array(int* len);


struct cel* create_rand_list(int len);


#endif /*RANDOM_ARRAYS_GEN_H*/