#include "quick_sort.h"

/*
int particione_aleatoria(int array[], int p, int r) {
    int aleatorio = p + rand() % (r - p + 1);
    int pivo = array[aleatorio];
    array[aleatorio] = array[r];
    array[r] = pivo;
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (array[j] <= pivo) {
            i++;
            int aux = array[i];
            array[i] = array[j];
            array[j] = aux;
        }
    }
    int aux = array[i + 1];
    array[i + 1] = array[r];
    array[r] = aux;

    return i + 1;
}

void quick_sort_rec(int array[], int p, int r) {
    if (p < r) {
        int lugar = particione_aleatoria(array, p, r);
        quick_sort_rec(array, p, lugar - 1);
        quick_sort_rec(array, lugar + 1, r);
    }
}
*/

void quick_sort_rec(int values[], int began, int end)
{
	int i, j, pivo, aux;
	i = began;
	j = end-1;
	pivo = values[(began + end) / 2];
	while(i <= j)
	{
		while(values[i] < pivo && i < end)
		{
			i++;
		}
		while(values[j] > pivo && j > began)
		{
			j--;
		}
		if(i <= j)
		{
			aux = values[i];
			values[i] = values[j];
			values[j] = aux;
			i++;
			j--;
		}
	}
	if(j > began)
		quick_sort_rec(values, began, j+1);
	if(i < end)
		quick_sort_rec(values, i, end);
}

uint64_t quick_sort(int array[], int p, int r)
{
    struct timeval start;
    struct timeval stop;

    gettimeofday(&start, NULL);

    /*
    if (p < r) {
        int lugar = particione_aleatoria(array, p, r);
        quick_sort_rec(array, p, lugar - 1);
        quick_sort_rec(array, lugar + 1, r);
    }
    */

    quick_sort_rec(array, p, r);

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

    srand(time(NULL));
    printf("%" PRIu64, quick_sort(arr, 0, len));
}