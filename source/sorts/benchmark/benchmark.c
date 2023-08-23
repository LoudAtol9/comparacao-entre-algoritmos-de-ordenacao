#include "benchmark.h"


uint64_t deltatime_to_uint64(struct timeval begin, struct timeval end)
{
    return (end.tv_sec - begin.tv_sec) * 1000000 + end.tv_usec - begin.tv_usec;
}


void copy_array(int array[], int copy[], int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        copy[i] = array[i];
    }
}

void bench(int n, int len)
{
    int i;

    int* array;
    int* array_copy;

    struct timeval start;
    struct timeval stop;

    uint64_t bubble = 0;
    uint64_t insertion = 0;
    uint64_t selection = 0;
    uint64_t merge = 0;

    array_copy = (int*) malloc(sizeof(int) * len);

    for (i = 0; i < n; i++)
    {
        array = create_rand_array(&len);

        copy_array(array, array_copy, len);

        gettimeofday(&start, NULL);
        selection_sort(array_copy, len);
        gettimeofday(&stop, NULL);

        selection = selection + deltatime_to_uint64(start, stop);

        copy_array(array, array_copy, len);

        gettimeofday(&start, NULL);
        bubble_sort(array_copy, len);
        gettimeofday(&stop, NULL);
        
        bubble = bubble + deltatime_to_uint64(start, stop);

        copy_array(array, array_copy, len);

        gettimeofday(&start, NULL);
        insertion_sort(array_copy, len);
        gettimeofday(&stop, NULL);

        insertion = insertion + deltatime_to_uint64(start, stop);




        
    }
    
}

int main(int argc, char const *argv[])
{
    bench(1, 1000);
    return 0;
}
