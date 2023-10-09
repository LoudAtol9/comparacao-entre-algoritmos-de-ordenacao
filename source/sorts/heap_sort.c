#include "heap_sort.h"

void maxHeapify(int array[], int len, int i)
{
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < len && array[esq] > array[maior])
        maior = esq;

    if (dir < len && array[dir] > array[maior])
        maior = dir;

    if (maior != i)
    {
        int aux = array[i];
        array[i] = array[maior];
        array[maior] = aux;

        maxHeapify(array, len, maior);
    }
}

uint64_t heap_sort(int array[], int len)
{
    struct timeval start;
    struct timeval stop;

    gettimeofday(&start, NULL);

    int i;

    for (int i = len / 2 - 1; i >= 0; i--)
        maxHeapify(array, len, i);

    for (int i = len - 1; i >= 0; i--)
    {
        int aux = array[0];
        array[0] = array[i];
        array[i] = aux;
        maxHeapify(array, i, 0);
    }

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

    printf("%" PRIu64, heap_sort(arr, len));
}

