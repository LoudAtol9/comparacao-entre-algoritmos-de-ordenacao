#ifndef TIME_CALC_H
#define TIME_CALC_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <inttypes.h>

uint64_t deltatime_to_uint64(struct timeval begin, struct timeval end);

#endif /*TIME_CALC_H*/