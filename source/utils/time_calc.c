#include "time_calc.h"

uint64_t deltatime_to_uint64(struct timeval begin, struct timeval end)
{
    return (end.tv_sec - begin.tv_sec) * 1000000 + end.tv_usec - begin.tv_usec;
}