#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Insertion Sort
//
// InsertionSort(A,n)
// for j <- 2 to n
//    do key <- A[j]
//       i <- j - 1
//       while i > 0 and A[i] > key
//         do A[i+1] = A[i]
//            i <- i - 1
//       A[i+1] <- key
//
// Theta(n^2)
// - moderately fast for small n
// - not fast at all for large n
void insertionSort(int *array, size_t n)
{
    int key;
    // note, i can become -1, if the 1st element needs to be interchanged. 
    int i,j;

    
    for(j = 1; j < n; j++)
    {
	key = array[j];
	i = j - 1;
	while((i >= 0) && (array[i] > key))
	{
	    array[i+1] = array[i];
	    i = i -1;
	}
	array[i+1] = key;
    }
    return;
}

// 
void bubbleSort(int *array, size_t n)
{
    unsigned int i, j;
    int temp;

    for(i = 0; i < n-1; i++)
    {
	for(j = i+1; j < n; j++)
	{
	    if(array[i] > array[j])
	    {
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	    }
	}
    }
    return;
}

// int compare function
int comp(const void *a, const void *b)
{
    int diff = *(int *)a - *(int *)b;
    if(diff > 0)
    {
        return 1;
    }
    else if(diff < 0)
    {
        return -1;
    }
    return 0;
}

void swap(void *a, void *b, size_t size)
{
    memcpy(a, b, size);
}

void bubbleSortGeneric(void *array, size_t num, size_t size, int (*comp)(const void *, const void *))
{
    unsigned int i, j;
    void *iIterator, *jIterator, *temp;

    temp = (void *)malloc(size);
    if(!temp)
        return;

    for(i = 0; i < num-1; i++)
    {
	for(j = i+1; j < num; j++)
	{
            iIterator = (void *)((char *)array + (i * size));
            jIterator = (void *)((char *)array + (j * size));

            if(comp(iIterator, jIterator) > 0)
            {
                swap(temp, iIterator, size);
                swap(iIterator, jIterator, size);
                swap(jIterator, temp, size);
            }
	}
    }
    return;
}

int main()
{
    int array[] = { 8, 2, 4, 9, 3, 6 };
    size_t n = sizeof(array)/sizeof(array[0]);
    unsigned int i;

    printf("Unsorted Array:");
    for(i = 0; i < n; i++)
    {
	printf(" %d",array[i]);
    }
    printf("\n");

    //insertionSort(array, n);
    //bubbleSort(array, n);
    bubbleSortGeneric(array, n, sizeof(int), comp);

    printf("Sorted Array:");
    for(i = 0; i < n; i++)
    {
	printf(" %d",array[i]);
    }
    printf("\n");

    return 0;
}
