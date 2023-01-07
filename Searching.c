#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Declaring Global Variables for calculating cost
int cost = 0;

// Cost Calculation
void Cost(int cost)
{
    printf("\n Total Cost: %d\n", cost);
}

// Function to print random numbers
int printRandom(int lower, int upper)
{
    int num = rand() % (upper - lower + 1) + lower;
    return num;
}

// Function to print sorted random number
int printSortedRandom(int size)
{
    int randomNum = 0;
    while (size-- > 0)
    {
        randomNum += rand() % 100;
        // printf("%d\n", num);
    }

    return randomNum;
}

// Function for linear Search
int linearSearch(int A[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (A[i] == element)
        {
            cost++;
            return i;
        }
    }
    return -1;
}

// Function for binary Search
int binarySearch(int A[], int size, int element)
{
    int mid, high, low;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        cost++;
        mid = (low + high) / 2;
        if (A[mid] == element)
        {
            cost++;
            return mid;
        }
        if (A[mid] < element)
        {
            cost++;
            low = mid + 1;
        }
        if (A[mid] > element)
        {
            cost++;
            high = mid - 1;
        }
        // else{
        //     return -1;
        // }
    }
    return -1;
}

int main()
{
    int size;
    int element;
    clock_t starttime, endtime;
    double totaltime;
    
    printf("How many numbers you want to generate? ");
    scanf("%d", &size);
    int arr[size];
    int choice;
    printf("Enter 1 for linear search \nEnter 2 for binary search\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        // Linear Search
        starttime = clock();
        printf("Start time: %f\n", (float)starttime);
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            arr[i] = printRandom(1, 1000);
            // printf("%d: %d\n", i, arr[i]);
            printf("%d\n", &arr[i]);
        }

        printf("Enter element to be searched:- ");
        scanf("%d", &element);
        printf("Index of the element:- %d\n", linearSearch(arr, size, element));
        // printf("Total cost: %d\n", cost);
        endtime = clock();
        printf("End time:%f\n", (float)endtime);
        totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
        break;
    case 2:
        // Binary Search
        starttime = clock();
        printf("Start time: %f\n", (float)starttime);
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            arr[i] = printSortedRandom(size);
            // printf("%d\n", arr[i]);
            printf( "%d\n", &arr[i]);
        }

        printf("Enter element to be searched:- ");
        scanf("%d", &element);
        printf("Index of the element:- %d\n", binarySearch(arr, size, element));
        // printf("Total cost: %d\n");
        endtime = clock();
        printf("End time:%f\n", (float)endtime);
        totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;

        break;
    default:
        break;
    }
    printf("\nTOTAL TIME: %f miili second\n", totaltime);
    return 0;
}
