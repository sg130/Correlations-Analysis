/*
    1 - Function to swap variables
    1 - Function for Menu Display and get option(an integer)
    2 - Overloaded Functions to accept data from user
    If Argument is a single array, it is used to accept Ungrouped data
    If Argument is 3 Arrays, it is used to accept lower limit, upper limit and frequency of different intervals
    Function returns an int, which is the number of elements/intervals accepted from user
*/

#include "stat.hpp"

void SwapNum(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int DispMenu(void)
{
        int ch;
        system("cls");
        printf("\n\t\t Main Menu\n");
        printf("\n 1. Print The Data");
        printf("\n 2. Print The Mean of Data");
        printf("\n 3. Print The Median of Data");
        printf("\n 4. Print The Mode of Data");
        printf("\n 5. Print The Variance of Data");
        printf("\n 6. Print The Standard Deviation of Data");
        printf("\n 7. Print The Coefficient of Standard Deviation");
        printf("\n 8. Print All Data and All Central Tendencies");
        printf("\n\n Enter your choice(0 to quit): ");
        scanf("%d",&ch);
        return ch;
}

int GetData(int D[])         //Ungrouped Data Array as Argument
{
    system("cls");           //To clear the Output Screen
    int N;
    printf("\nEnter number of elements:(max 32000)");
    scanf("%d",&N);
    printf("Enter the data elements\n");
    for(int i = 0; i<N; i++)
        scanf("%d",&D[i]);

    for(int i = 0; i<N-1; i++)                      //Sorting the Data Elements in Ascending Order
    {
        int mini = D[i];
        int pos = i;
        for(int j = i+1; j<N; j++)
        {
            if(mini > D[j])
            {
                mini = D[j];
                pos = j;
            }
        }
        SwapNum(&D[i],&D[pos]);
    }

    PrintData(D,N);            //Printing the Final Data
    return N;
}

int GetData(int xl[], int xu[], int freq[])          //Grouped Data Intervals and their frequencies as Arguments
{
    system("cls");           //To clear the Output Screen
    int N;
    printf("\nEnter number of intervals: (max 32000)");
    scanf("%d",&N);
    printf("Enter the lower limit, upper limit and frequency of intervals\n(Interval is exclusive of Upper Limit)(Ensure no overlapping intervals and uniform class width)\n");
    for(int i = 0; i<N; i++)
        scanf("%d%d%d",&xl[i],&xu[i],&freq[i]);

    for(int i = 0; i<N-1; i++)                      //Sorting the Data Intervals in Ascending Order
    {
        int mini = xl[i];
        int pos = i;
        for(int j = i; j<N; j++)
        {
            if(mini > xl[j])
            {
                mini = xl[j];
                pos = j;
            }
        }
        SwapNum(&xl[i],&xl[pos]);
        SwapNum(&xu[i],&xu[pos]);
        SwapNum(&freq[i],&freq[pos]);
    }

    PrintData(xl,xu,freq,N);
    return N;
}
