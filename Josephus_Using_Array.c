#include <stdio.h>
char array[100];


int Josephus(int n, int k)
{
    k--;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = 1;
    }
    int flag = 0, z = 0;
    int num = 1;
    while (flag < (n - 1))
    {
        while (num <= k)
        {
            z++;
            z = z % n;
            if (arr[z] == 1)
            {
                num++;
            }
        }
        num = 1;
        printf("\nPlayer %c eleminated", array[z]);
        arr[z] = 0;
        flag++;
        z++;
        z = z % n;
        while (arr[z] == 0)
        {
            z++;
            z = z % n;
        }
    }
    return z ;
}


void main()
{
    int winner, n, k, start, i;

    printf("Enter the number of players : ");
    scanf("%d", &n);

    printf("Enter the elmenation value : ");
    scanf("%d", &k);
    
    printf("Players are : ");
    for(i = 0; i < n; i++)
    {
        array[i] = 'A' + i;
    }
     
    for(i = 0; i < n; i++)
    {
        printf(" %c ", array[i]);
    }

    winner = Josephus(n, k);
    printf("\nWinner : %c", array[winner]);
}