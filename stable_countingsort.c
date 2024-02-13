// counting sort
// The following algorithm is stable
// constraints is:
// elements of the input unsorted array 
//should be non negative number
# include<stdio.h>
# include<stdlib.h>
# include <limits.h>


// print array function
// it will be uswd if require
void printarray(int *arr,int n)
{
    
    for(int i =0; i < n; i++)
    {
        printf("%d \t",arr[i]);
    }
}


int Stable_CountingSort(int *arr,int size)
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
   // find the maximum element in the array arr[]
    int max_element = INT_MIN;
    for(int i = 0; i < size; i++)
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
   // store the count of the entries of arr[]
   for(int i =0; i < size; i++)
   {
    count[arr[i]]++;
   }
   
   // Store the cummulative count of each array
  for (int i = 1; i <= max_element; i++) 
  {
    count[i] += count[i-1];
  }
   // define an output array output[size]
   int output[size];
  // Find the index of each element of the original array in count array 
  // and place the elements in output array
  for (int i = size - 1; i >= 0; i--) 
  {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }

  // print the output array...
  printarray(output,size);

  return 0;
    
}
// main function
int main()
{   
    printf("The sorted array by counting sort algorithm is:\n");
    int arr[] = {5,2,1,0,5,0,11,10,3,2,78,43,5,3,3,8,7};
    //int arr[] = {5,2,1,0,5,0,11,-10,3,2,78,43,5,3,3,8,7}; // use this array to check: negative enntry does not support
    int size = sizeof(arr)/sizeof(int);
    Stable_CountingSort(arr,size);
return 0;
}