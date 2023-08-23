#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "../utils/linked_list.h"
#include "../sorts/benchmark/random_arrays_gen.h"
#include "../sorts/test/asserts_for_sorting.h"

void insertion_sort(int array[], int len);

void din_insertion_sort(struct cel** head);

#endif /*INSERTION_SORT_H*/