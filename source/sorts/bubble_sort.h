#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <stdio.h>
#include <stdbool.h>
#include "../utils/linked_list.h"
#include "../sorts/benchmark/random_arrays_gen.h"
#include "../sorts/test/asserts_for_sorting.h"


void bubble_sort(int array[], int len);

void din_bubble_sort(struct cel** head);

#endif /*BUBBLE_SORT_H*/