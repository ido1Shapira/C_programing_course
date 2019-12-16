#include <stdio.h>
#include "isort.h"

#define SIZE 50
int main(){
    int arr[SIZE];
    for (size_t i = 0; i < SIZE; i++)
    {
        scanf("%d\n",(arr+i));
    }
    size_t i;
    insertion_sort(arr,SIZE);
    for (i = 0; i < SIZE-1; i++)
    {
        printf("%d,",*(arr+i));
    }
    printf("%d\n",*(arr+i));
    return 0;
}
