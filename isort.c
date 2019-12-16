#include <stdio.h>
#include "isort.h"
void shift_element(int *arr ,int i)
{
   for ( int *value = (arr+i); value > arr;value--)
   {
       *value = *(value-1);
    }  
}
void insertion_sort(int *arr , int len)
{
    for (size_t i = 0; i < len; i++)
    {
        int count = 0;
        int *p;
        for (p = (arr+i); p > arr && *(arr+i) < *(p-1); p--)
        {
           count++;
        }
        if(count >0) {
            int last= *(arr+i);
            shift_element(p,count);
            *p = last;
        }
    }
    
}