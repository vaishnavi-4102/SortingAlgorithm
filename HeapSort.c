#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
int cost=0;
// Function to print random numbers
int printRandom(int lower, int upper, int count){
    int num = rand()%(upper -lower +1)+lower;
    return num;
}


void heapify(int arr[], int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left <n && arr[left]>arr[largest]){
        cost++;
        largest= left;
    }

    if(right<n && arr[right]>arr[largest]){
        cost++;
        largest = right;
    }

    if(largest != i){
        int temp  = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        cost++;
        heapify(arr, n ,largest);
    }
}

void heapSort(int arr[],int n){
    for(int i = n/2 -1; i>=0; i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
  heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        cost++;
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr,i,0);
    }
}

int main()
{
    clock_t starttime,endtime;
    double totaltime;

 FILE *fptr;
    fptr = fopen("input.txt","w");
    int number;
    
    printf("How many numbers you want to generate? ");
    scanf("%d",&number);
    srand(time(0));
    int arr[number];
    for (int i = 0; i < number; i++)
    {
        arr[i]=printRandom(1,1000000,number);
        fprintf(fptr,"%d\n",arr[i]);
    }
    fclose(fptr);

    starttime = clock();
    printf("Start time: %f\n",(float)starttime);
    // Function Call
    heapSort(arr,number); 
    endtime = clock();
    printf("End time:%f\n", (float)endtime);
    totaltime = ((double)(endtime-starttime))/CLOCKS_PER_SEC;
    printf("Total Cost: %d\n",cost);
    FILE *ptr;
    ptr = fopen("output.txt","w");
    for (int i = 0; i < number; i++)
    {
        fprintf(ptr,"%d\n",arr[i]);
    }
    fclose(ptr);
printf("\nTOTAL TIME: %f milli second\n",totaltime);
//     return 0;
}