#include<stdlib.h>
#include <stdio.h>
     
void create();
void displayForward();
void displayBackwark();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
 
 
struct node
{
    int data;
    struct node *next;
    struct node *previous;
};
struct node *start=NULL;


void main()     
{
    int choice;
    while(1)
    {        
        printf("\n\n----------------MENU----------------");
        printf("\n1. Create");
        printf("\n2. Display Forward");
        printf("\n3. Display Backward");
        printf("\n4. Insert at the beginning");
        printf("\n5. Insert at the end");
        printf("\n6. Insert at specified position");
        printf("\n7. Delete from beginning");
        printf("\n8. Delete from the end");
        printf("\n9. Delete from specified position");
        printf("\n10. Exit");
        printf("\n--------------------------------------");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                create();
            break;
            
            case 2:
                displayForward();
            break;

            case 3:
                displayBackwark();
            break;
        
            case 4: 
                insert_begin();
            break;
        
            case 5:
                insert_end();
            break;
       
            case 6:
                insert_pos();
            break;

            case 7:
                delete_begin();
            break;
            
            case 8:
                delete_end();
            break;

            case 9:
                delete_pos();
            break;
                
            case 10:
                exit(0);
            break;
                        
            default:
                printf("Wrong Choice : ");
            break;
        }
    }
}


void create()
{
    struct node *temp, *ptr;
    temp = malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Out of Memory Space");
        exit(0);
    }

    printf("Enter the data value for the node : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->previous = NULL;
    
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next=temp;
        temp->previous=ptr;
    }
}


void displayForward()
{
    struct node *ptr;
    if(start == NULL)
    {
        printf("List is empty");
        return;
    }
    else
    {
        ptr = start;
        printf("The List elements are : ");
            
        while(ptr != NULL)
        {
            printf("%d\t", ptr->data );
            ptr = ptr->next ;
        }
    }
}

void displayBackwark()
{
    struct node *ptr, *ptr2;
    if(start == NULL)
    {
        printf("List is empty");
        return;
    }
    else
    {
        ptr = start;
        printf("The List elements are : ");
            
        while(ptr != NULL)
        {
            ptr2 = ptr;
            ptr = ptr->next;
        }
        while(ptr2 != NULL)
        {
            printf("%d\t", ptr2->data);
            ptr2 = ptr2->previous;
        }
    }
}


void insert_begin()
{
    struct node *temp;
    temp = malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Out of Memory Space");
        return;
    }

    printf("Enter the data value for the node : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->previous = NULL;
    
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->next = start;
        start->previous = temp;
        start = temp;
    }
}


void insert_end()
{
    struct node *temp, *ptr;
    temp = malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Out of Memory Space");
        return;
    }

    printf("Enter the data value for the node : ");
    scanf("%d", &temp->data );
    temp->next = NULL;
    temp->previous = NULL;
    
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while(ptr->next != NULL)
        {
            ptr = ptr->next ;
        }
        ptr->next = temp;
        temp->previous=ptr;
    }
}


void insert_pos()
{
    struct node *ptr, *temp;
    int i,pos;
    temp = malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Out of Memory Space");
        return;
    }
    
    printf("Enter the position for the new node to be inserted : ");
    scanf("%d",&pos);
    
    printf("Enter the data value of the node : ");
    scanf("%d",&temp->data) ;
    temp->next = NULL;
    temp->previous = NULL;
    
    if(pos == 0)
    {
        temp->next = start;
        start->previous = temp;
        start = temp;
    }
    else
    {
        for(i = 0, ptr = start; i < pos - 1; i++) 
        { 
            ptr = ptr->next;
            if(ptr == NULL)
            {
                printf("Position not found : [Handle with care]");
                return;
            }
        }
        temp->next = ptr->next;
        ptr->next->previous = temp;
        temp->previous = ptr;
        ptr->next = temp;
    }
}


void delete_begin()
{
    struct node *ptr;
    if(ptr == NULL)
    {
        printf("List is Empty");
        return;
    }
    else
    {
        ptr = start;
        start = start->next;
        start->previous = NULL;
        ptr->next = NULL;
        printf("The deleted element is : %d",ptr->data);
        free(ptr);
    }
}


void delete_end()
{
    struct node *temp, *ptr;
    if(start == NULL)
    {
        printf("List is Empty");
        exit(0);
    }
    else if(start->next == NULL)
    {
        ptr = start;
        start = NULL;
        printf("The deleted element is : %d", ptr->data);
        free(ptr);
    }
    else
    {
        ptr = start;
        while(ptr->next != NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next = NULL;
        ptr->previous = NULL;
        printf("The deleted element is : %d",ptr->data);
        free(ptr);
    }
}


void delete_pos()
{
    int i, pos;
    struct node *temp, *ptr;
    if(start == NULL)
    {
        printf("The List is Empty");
        exit(0);
    }
    else
    {
        printf("Enter the position of the node to be deleted : ");
        scanf("%d", &pos);
        if(pos == 0)
        {
            ptr = start;
            start = start->next ;
            start->previous = NULL;
            ptr->next = NULL;
            printf("The deleted element is : %d", ptr->data  );
            free(ptr);
        }
        else
        {
            ptr = start;
            for(i = 0; i < pos; i++) 
            { 
                temp = ptr; 
                ptr = ptr->next;
                if(ptr == NULL)
                {
                    printf("Positionnot Found");
                    return;
                }
            }
            temp->next = ptr->next;
            ptr->next->previous = temp;
            printf("nThe deleted element is : %d ", ptr->data );
            free(ptr);
        }
    }
}