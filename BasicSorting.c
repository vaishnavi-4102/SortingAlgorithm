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
int printRandom(int lower, int upper, int count)
{
    int num = rand() % (upper - lower + 1) + lower;
    return num;
}
// Selection Sort Function
void selectionSort(int A[], int num)
{
    int minIndex;
    for (int i = 0; i < num - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < num; j++)
        {
            cost++;
            if (A[j] < A[minIndex])
            {
                cost++;
                minIndex = j;
            }
        }
        // Swap
        cost++;
        int temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }
}

// Bubble Sort Function
void bubbleSort(int A[], int n)
{
    // For passes
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            cost++;
            if (A[j] > A[j + 1])
            {
                cost++;
                // Swap
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                cost++;
            }
        }
    }
}

// Insertion Sort Function
void insertionSort(int arr[], int num)
{
    int j;
    for (int i = 1; i <= num - 1; i++)
    {
        cost++;
        int key = arr[i];
        j = i - 1;
        while (j > 0 && arr[j] > key)
        {
            cost++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    clock_t starttime, endtime;
    double totaltime;

    FILE *fptr;
    fptr = fopen("input.txt", "w");
    int number;

    printf("How many numbers you want to generate? ");
    scanf("%d", &number);

    int arr[100000];
    int choose;
    printf("For best case:1\nFor avg case:2\nFor worst case:3\n");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        // Best Case
        for (int i = 0; i < number; i++)
        {
            arr[i] = i;
            fprintf(fptr, "%d\n", &arr[i]);
        }

        break;
    case 2:
        // Avg Case
        srand(time(0));
        for (int i = 0; i < number; i++)
        {
            arr[i] = printRandom(1, 10000, number);
            fprintf(fptr, "%d\n", arr[i]);
        }
        break;
    case 3:
        // Worst case
        for (int i = number; i > 0; i--)
        {
            arr[i] = i;
            fprintf(fptr, "%d\n", arr[i]);
        }
        break;
    default:
        break;
    }

    fclose(fptr);

    int choice;
    printf("Enter your choice for sorting:\n");
 
    printf("For Insertion: 1\nFor Bubble: 2\nFor Selection: 3\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        starttime = clock();
        printf("Start time: %f\n", (float)starttime);
        // Function Call
        insertionSort(arr, number);
        endtime = clock();
        printf("End time:%f\n", (float)endtime);
        Cost(cost);
        totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
        break;

    case 2:
        starttime = clock();
        printf("Start time: %f\n", (float)starttime);
        // Function Call
        bubbleSort(arr, number);
        endtime = clock();
        printf("End time:%f\n", (float)endtime);
        Cost(cost);
        totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;

    case 3:
        starttime = clock();
        printf("Start time: %f\n", (float)starttime);
        // Function Call
        selectionSort(arr, number);
        endtime = clock();
        printf("End time:%f\n", (float)endtime);
        Cost(cost);
        totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
    default:
        break;
    }

    FILE *ptr;
    ptr = fopen("output.txt", "w");
    for (int i = 0; i < number; i++)
    {
        fprintf(ptr, "%d\n", arr[i]);
    }
    fclose(ptr);

    printf("\nTOTAL TIME: %f milli second\n", totaltime);
    return 0;
}