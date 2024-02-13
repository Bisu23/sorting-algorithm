// counting sort
// The following algorithm is not stable
// constraints is:
// elements of the input unsorted array 
//should be non negative number
# include<stdio.h>
# include<stdlib.h>
#include <limits.h>


// print array function
// it will be uswd if require
void printarray(int *arr,int n)
{
    
    for(int i =0; i < n; i++)
    {
        printf("%d \t",arr[i]);
    }
}



// The counting sort algorithm implimentation
// time complexity and spsce complexity both are O(n+k)
// where n := number of elements in the unsorted array
// and k := maximium element in the unsorted array
int CountingSort(int *arr,int n)
    {
    // check each element is non negative
    for(int i =0; i < n; i++)
    {
      if(arr[i] < 0)
      {
        printf("The %d th entry is negative\n",i);
        printf("Plese enter all non negative number");
        exit(1);
        
      }
    }
   // find the maximum element in the array arr[]
    int max_element = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if (max_element < arr[i])
        {
            max_element = arr[i];
        }

    }
   // define an array count[maximum_element+1]
   // of size of maximun element of the array[]
   int count[max_element+1];
   // initially store the array count[] with zero
   for(int i = 0;  i <= max_element; i++)
   {
    count[i] = 0;
   } 
   // Now traverse the whole input 
   // unsorted array arr[] and 
   // count the entries of arr[]
   for(int i =0; i < n; i++)
   {
    count[arr[i]]++;
   }
   // At this step, traverse the count array count[]
   // skip the j-th index if count[j]==0
   for(int i = 0; i <= max_element; i++)
   {
    if (count[i] == 0)
    {
        continue;
    }
    else
    {
        for(int j = 0; j < count[i]; j++)
        {
            printf("%d \t",i);
        }
    }
   }

return 0;
}


int main()
{   
    printf("The sorted array by counting sort algorithm is:\n");
    int arr[] = {5,2,1,0,5,0,11,10,3,2,78,43,5,3,3,8,7};
    //int arr[] = {5,2,1,0,5,0,11,-10,3,2,78,43,5,3,3,8,7}; // use this array to check: negative enntry does not support
    int size = sizeof(arr)/sizeof(int);
    CountingSort(arr,size);
return 0;
}