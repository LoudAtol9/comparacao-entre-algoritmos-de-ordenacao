#include "merge_sort.h"

void merge(int array[], int p, int q, int r)
{
    int esq[q - p + 1], dir[r - q];

    for (int i = 0; i < q - p + 1; i++)
        esq[i] = array[p + i];
    for (int j = 0; j < r - q; j++)
        dir[j] = array[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < q - p + 1 && j < r - q)
    {
        if (esq[i] <= dir[j])
        {
            array[k] = esq[i];
            i++;
        }
        else
        {
            array[k] = dir[j];
            j++;
        }
        k++;
    }

    while (i < q - p + 1)
    {
        array[k] = esq[i];
        i++;
        k++;
    }

    while (j < r - q)
    {
        array[k] = dir[j];
        j++;
        k++;
    }
}

void merge_sort_rec(int array[], int p, int r)
{
    if (p >= r)
        return;
    int q = (p + r) / 2;
    merge_sort_rec(array, p, q);
    merge_sort_rec(array, q + 1, r);
    merge(array, p, q, r);
}

uint64_t merge_sort(int array[], int p, int r)
{
    struct timeval start;
    struct timeval stop;

    gettimeofday(&start, NULL);

    if (p >= r)
    {
        gettimeofday(&stop, NULL);
        return deltatime_to_uint64(start, stop);;
    }
        
    int q = (p + r) / 2;
    merge_sort_rec(array, p, q);
    merge_sort_rec(array, q + 1, r);
    merge(array, p, q, r);

    gettimeofday(&stop, NULL);

    return deltatime_to_uint64(start, stop);
}

int main(int argc, char const *argv[])
{
    int i;
    int len;
    int* arr;

    if (argc < 2)
        return 0;

    len = argc - 1;
    arr = (int*) malloc(sizeof(int) * len);
    
    for (i = 0; i < len; i++)
        arr[i] = atoi(argv[i + 1]);

    printf("%" PRIu64, merge_sort(arr, 0, len));
}