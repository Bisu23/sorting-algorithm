//radix is non comparison base sorting algorithm
// for this we need a stable sorting algorithm
// for this resone we shall use satable version
// of counting soting algorithm

# include<stdio.h>
# include<stdlib.h>
# include <limits.h>


// print array function
// it will be used if require
void printarray(int *arr,int size)
{
    
    for(int i =0; i < size; i++)
    {
        printf("%d \t",arr[i]);
    }
}

// find the maximum element in the array arr[]

int find_max(int *arr, int size)
{
    int max_element = INT_MIN;
    for(int i = 0; i < size; i++)
    {
        if (max_element < arr[i])
        {
            max_element = arr[i];
        }

    }

    return max_element;
}


// next counting sort , which is stable
int Stable_CountingSort(int *arr,int size, int index)
{
    // check each element is non negative
    for(int i =0; i < size; i++)
    {
      if(arr[i] < 0)
      {
        printf("The %d th entry is negative\n",i);
        printf("Plese enter all non negative number");
        exit(1);
        
      }
    }
    // define an array count[10]
   // of size of maximun element of the array[]
   int count[10];
   // initially store the array count[] with zero
   for(int i = 0;  i < 10; i++)
   {
    count[i] = 0;
   } 

   // Now traverse the whole input 
   // unsorted array arr[] and 
   // store the count of the entries of arr[]
   for(int i =0; i < size; i++)
   {
    int digit = (arr[i] / index) % 10;
    count[digit]++;
   }
   
   // Store the cummulative count of each array
  for (int i = 1; i < 10; i++) 
  {
    count[i] += count[i-1];
  }
   // define an output array output[size]
   int output[size];
  // Find the index of each element of the original array in count array 
  // and place the elements in output array
  for (int i = size - 1; i >= 0; i--) 
  {
    int digit = (arr[i] / index) % 10 ;
    output[count[digit] - 1] = arr[i];
    count[digit]--;
  }

  // print the output array...
  // printarray(output,size);
  // now store the array in sorted (least to largest) order

  for(int i = 0; i < size; i++)
  {
    arr[i] = output[i];
  }



    
}

// Radix sort function...
int RadixSort(int *arr, int size)
{
 // find maximum element in the array
 int max_element = find_max(arr,size);
 
 for(int index = 1; max_element/index > 0; index *= 10)
 {
    Stable_CountingSort(arr,size,index);
 }
}

// main function
int main()
{   
    printf("The sorted array by radix sort algorithm is:\n");
    int arr[] = {5,2,1,0,511,10,11,10,3,2,78,430,5,3,3,8,7};
    //int arr[] = {5,2,1,0,5,0,11,-10,3,2,78,43,5,3,3,8,7}; // use this array to check: negative enntry does not support
    int size = sizeof(arr)/sizeof(int);
    RadixSort(arr,size);
    printarray(arr,size);
}

