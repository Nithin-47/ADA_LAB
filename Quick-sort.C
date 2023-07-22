#include <stdio.h>
 

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 

int partition(int arr[], int low, int high)
{
    
    int pivot = arr[high];
 
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {

        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
 
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 

int main()
{
    int A[] = { 10, 7, 8, 9, 1, 5 };
    int N = sizeof(A) / sizeof(A[0]);
 
    // int N,A[N];
    // printf("Enter the size of the Array:");
    // scanf("%d",&N);

    // printf("Enter the elements:");
    // for(int i=0;i<N;i++){
    //     scanf("%d",&A[i]);
    // }
    
    quickSort(A, 0, N - 1);
    printf("Sorted array: \n");
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);



    return 0;
}
