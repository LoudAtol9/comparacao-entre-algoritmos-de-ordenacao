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

void static_bench(int n, int len)
{
    int i;

    int* array;
    int* array_copy;

    struct timeval start;
    struct timeval stop;

    double bubble = 0;
    double insertion = 0;
    double selection = 0;
    double merge = 0;
    double quick = 0;

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

        /*resto das funcoes*/
    }

    free(array);
    free(array_copy);

    bubble = bubble/len;
    selection = selection/len;
    insertion = insertion/len;
    merge = merge/len;
    quick = quick/len;

    printf("%f\n", selection);
    printf("%f\n", bubble);
    printf("%f\n", insertion);
    printf("%f\n", merge);
    printf("%f\n", quick);
}


void dinamic_bench(int n, int len)
{
    int i;

    struct cel* list;
    struct cel* list_copy;

    struct timeval start;
    struct timeval stop;

    double bubble = 0;
    double insertion = 0;
    double selection = 0;
    double merge = 0;
    double quick = 0;

    for (i = 0; i < len; i++)
    {
        list = create_rand_list(len);
        list_copy = make_copy(list);

        gettimeofday(&start, NULL);
        din_selection_sort(list_copy);
        gettimeofday(&stop, NULL);

        selection = selection + deltatime_to_uint64(start, stop);

        copy_elems(list, list_copy);

        gettimeofday(&start, NULL);
        din_bubble_sort(list_copy);
        gettimeofday(&stop, NULL);

        bubble = bubble + deltatime_to_uint64(start, stop);

        copy_elems(list, list_copy);

        gettimeofday(&start, NULL);
        din_insertion_sort(list_copy);
        gettimeofday(&stop, NULL);

        insertion = insertion + deltatime_to_uint64(start, stop);

        copy_elems(list, list_copy);

        /*resto das funcoes*/

        free_list(list);
        free_list(list_copy);
    }

    bubble = bubble/len;
    selection = selection/len;
    insertion = insertion/len;
    merge = merge/len;
    quick = quick/len;

    printf("%f\n", selection);
    printf("%f\n", bubble);
    printf("%f\n", insertion);
    printf("%f\n", merge);
    printf("%f\n", quick);

}


void benchmark(char* mode, int n, int len)
{
    if (mode == "array")
        static_bench(n, len);
    if (mode == "list")
        dinamic_bench(n, len);
}

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        printf("Missing something\n");
        printf("USAGE: list_or_array | lenght_of_array/list | sample");
        return 1;
    }

    char* mode = argv[0];
    int length = atoi(argv[1]);
    int sample = atoi(argv[2]);

    if(length <= 0 || sample <= 0)
    {
        printf("Invalid Number\n");
        printf("Size and length can't be zero or below zero\n");
        return 1;
    }

    benchmark(mode, sample, length);
    return 0;
}
