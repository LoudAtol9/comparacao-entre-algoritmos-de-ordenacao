#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "../utils/linked_list.h"
#include "../sorts/benchmark/random_arrays_gen.h"
#include "../sorts/test/asserts_for_sorting.h"

void selection_sort(int array[], int len);

void din_selection_sort(struct cel** head);

#endif /*SELECTION_SORT_H*/