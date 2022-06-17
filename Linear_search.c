
// Ram is given n boxes kept one after the other each containing a number inside it. The boxes are indexed from 0 to n-1.

// Now Ram is asked to find the position of the box in which a specific number is stored. 

// Ram opens each box one-by-one and checks whether that box contains the given number or not.

// Implement the above scenario using linear search technique.

// Input Format

// The First line reads an integer representing the number of boxes.

// The Second line reads the Numbers (elements) hidden in the boxes.

// The Third line reads the Number to be searched .

// Output format

// Display the position(index) of the box in which the Number is found.

// if not found,display"Number not found."

#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    int arr[a];
    for (int i=0;i<a;i++)
    {
        scanf("%d",&arr[i]);
    }
    int b;
    scanf("%d",&b);
    int flag=0,i;
    for (i=0;i<a;i++)
    {
        if(arr[i]==b)
        {flag=1;
        break;}
    }
    if(flag==1)
    printf("Number found at location : %d",i);
    else
    printf("Number not found.");
    
}
