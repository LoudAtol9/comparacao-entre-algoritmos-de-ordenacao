#ifndef ASSERTS_FOR_SORTING_H
#define ASSERTS_FOR_SORTING_H

#include <stdbool.h>
#include <assert.h>

#include "../../utils/linked_list.h"


void array_is_ordered(int array[], int len);

void list_is_ordered(struct cel* head);

#endif /*ASSERTS_FOR_SORTING_H*/