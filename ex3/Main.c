#include <stdio.h>
#include "isort.h"

#define SIZE 50
int main(){
    int arr[SIZE];
     for (size_t i = 0; i < SIZE; i++)
    {
        printf("Insert the %ld number: ",i+1);
        
        scanf("%d\n",(arr+i));
    }
    printf("The original array:\n");
       for (size_t i = 0; i < SIZE; i++)
    {
        printf("%d ",*(arr+i));
    }
    insertion_sort(arr,SIZE);
    printf("\nThe sorted array:\n");
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
    return 0;
}
