#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cost = 0;            // loop
int swap = 0;            // swap
int comparison = 0;      // comparison
int merge_cost = 0;      // merge-loop
int comparison_cost = 0; // merge Comparison

// Function to print random numbers
int printRandom(int lower, int upper, int count)
{
    int num = rand() % (upper - lower + 1) + lower;
    return num;
}

// Cost Calculate Function of quick sort
void quickCost(int comparison, int swap, int cost)
{
    int totalcost = comparison + swap + cost;
    printf("Total cost: %d\n", totalcost);
}

// Cost Calculate Function of merge sort
void mergeCost(int comparison_cost, int merge_cost)
{
    int total_cost = comparison_cost + merge_cost;
    printf("Total Cost: %d\n", total_cost);
}

// merge function
void merge(int A[], int mid, int low, int high)
{
    int i, j, k;
    int B[high + 1];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        merge_cost++;
        if (A[i] < A[j])
        {
            comparison++;
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            comparison++;
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        merge_cost++;
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        merge_cost++;
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

// Recursive MergeSort

void MergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = low + (high - low) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

// quickSort
int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i, j;
    i = low + 1;
    j = high;
    do
    {
        cost++;
        while (A[i] < pivot)
        {
            comparison++;
            i++;
        }
        while (A[j] > pivot)
        {
            comparison++;
            j--;
        }
        if (i < j)
        {
            comparison++;
            // Swapping
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            swap++;
        }

    } while (i < j);

    comparison++;
    swap++;

    int temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

// Recursive Quick Sort
void quickSort(int A[], int low, int high)
{
    int comparison_cost, cost, swap_cost;
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(A, low, high); // Index of pivot after partition
        quickSort(A, low, partitionIndex - 1);    // sort left subarray
        quickSort(A, partitionIndex + 1, high);   // sort right subarray
    }
    // quickCost(comparison_cost,swap_cost,cost);
}

int main()
{
    clock_t starttime, endtime;
    double totaltime;

    FILE *fptr;
    // Creating a input file
    fptr = fopen("input.txt", "w");
    int number;

    printf("How many numbers you want to generate? ");
    scanf("%d", &number);
    srand(time(0));
    int arr[100000];
    for (int i = 0; i < number; i++)
    {
        // Storing random numbers in array
        arr[i] = printRandom(1, 1000000, number);
        // Printing generated random numbers in file
        fprintf(fptr, "%d\n", arr[i]);
    }
    // Closing the file
    fclose(fptr);

    // Selection of sorting
    int choice;
    printf("Enter your choice\n");
    printf("For quicksort: 1 \n For mergesort: 2\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        // For quick Sort
        starttime = clock();
        printf("Start time: %f\n", (float)starttime);
        quickSort(arr, 0, number);
        quickCost(comparison, swap, cost);
        endtime = clock();
        printf("End time:%f\n", (float)endtime);
        totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;

        break;
    case 2:
        // For merge sort
        starttime = clock();
        printf("Start time: %f\n", (float)starttime);
        MergeSort(arr, 0, number);
        mergeCost(comparison_cost, merge_cost);
        endtime = clock();
        printf("End time:%f\n", (float)endtime);
        totaltime = ((double)(endtime - starttime) / CLOCKS_PER_SEC);
    default:
        break;
    }

    FILE *ptr;
    // Printing sorted array in output file
    ptr = fopen("output.txt", "w");
    for (int i = 1; i <= number; i++)
    {
        fprintf(ptr, "%d\n", arr[i]);
    }
    fclose(ptr);

    printf("\nTOTAL TIME: %f miili second\n", totaltime);
    return 0;
}