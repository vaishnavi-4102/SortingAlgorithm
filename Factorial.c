#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cost=0;
// Recursive Call
double RecursiveFact(double num)
{
    double result;
    if (num >= 1)
    {
        cost++;
        result = num * RecursiveFact(num - 1);
        return result;
    }
    else {
        return 1;
    }
    
}

// Iterative Call
double IterativeFact(double num){
    double factorial = 1;
    for(int i=1;i<=num;i++){
      factorial=factorial*i;
      cost++;
  }
      return factorial;   
    }

int main()
{
    int choice;
    double number;
    
    clock_t starttime, endtime;
    double totaltime;
    printf("Enter the number:- \n");
    scanf("%ld", &number);
    printf("Enter 1 for Recursive Call\nEnter 2 for iterative call\n");
    scanf("%ld",&choice);
    switch (choice)
    {
    case 1:
    
        starttime = clock();
        printf("Start time: %f\n", (float)starttime);
        printf("Factorial of entered number is %ld\n", RecursiveFact(number));
        printf("Total Cost: %d\n",cost);
        endtime = clock();
        printf("End time:%f\n", (float)endtime);
        totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
        break;
    case 2:
    starttime = clock();
        printf("Start time: %f\n", (float)starttime);
        printf("Factorial of entered number is %ld\n",IterativeFact(number));
        printf("Total Cost: %d\n",cost);
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