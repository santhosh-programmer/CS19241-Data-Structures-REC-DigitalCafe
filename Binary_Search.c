// Given a sorted array of  N integers representing the rollno of students in class and a target student  rollno, determine if the target student  exists in the class using the binary search algorithm. If student exists in the class, print the seat number of the student. Consider the seat number as the index of the sorted array.

// Input Format

// The first line reads the array of student register numbers

// The second line reads the search element

// Output Format

// Seat number of the student

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int binarySearch(int arr[], int n, int x)
{
    int first = 0, last = n - 1, mid;
    while (first <= last)
    {
        mid = (first + last) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (x > arr[mid])
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    return -1;
}
int main()
{
    char arr[1000];
    int arrr[100];
    int x, k = 0, a, n = 0;
    scanf("%[^\n]", arr);
    scanf("%d", &x);
    char *y = strtok(arr, " ");
    while (y != NULL)
    {
        a = atoi(y);
        arrr[n] = a;
        n++;
        k++;
        y = strtok(NULL, " ");
    }
    if (binarySearch(arrr, n, x) != -1)
    {
        printf("%d", binarySearch(arrr, n, x));
    }
    return 0;
}
