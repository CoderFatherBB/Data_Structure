#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
    char player_id;
    struct node *next;
};
struct node *start, *ptr , *new_node;

void display(int n, struct node *beg)
{
	struct node *temp;
	int count;

	temp = beg;
	printf(" : ");
		
	for (count = n; count >= 1; count--)
	{
		printf(" %c ", temp -> player_id );
		temp = temp -> next ;
	}
	printf("\n");
}

void main()
{
    int n, k, i, count;

    printf("\nEnter the number of players : ");
    scanf("%d", &n);
    printf("\nEnter the value of k (every kth player gets eliminated) : ");
    scanf("%d", &k);

	start = malloc(sizeof(struct node));
	start -> player_id = 'A';
	ptr = start;
	for (i = 2; i <= n; i++)
	{
    	new_node = malloc(sizeof(struct node));
    	ptr -> next = new_node;
    	new_node -> player_id = 'A'+ i - 1;
    	new_node -> next = start;
    	ptr = new_node;
	}

	display(n, start);

	for (count = n; count > 1; count--)
	{
    	for (i = 0 ; i < k - 1; ++i)
        	ptr = ptr -> next;
        	printf("\n%c deleted\n", ptr -> next -> player_id);
   		ptr -> next = ptr -> next -> next;
		display(count - 1, ptr -> next);
	}
	printf("\nThe Winner is Player %c", ptr -> next -> player_id);
}