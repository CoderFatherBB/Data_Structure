/* C Program to Implement operations in Threaded Binary Search Tree */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int left_flag;
    int info;
    int right_flag;
    struct node *right;
};

struct node *head = NULL;
void create_header(struct node *root)
{
    head = malloc(sizeof(struct node));
    head->info = 32767;
    head->left = root;
    head->right = head;
    head->left_flag = 0;
    head->right_flag = 1;
}

struct node *in_succ(struct node *p);
struct node *in_pred(struct node *p);
struct node *insert(struct node *root, int ikey);
void inorder( struct node *root);
void preorder( struct node *root);
void postorder( struct node *root);

int count = 0;
int array[100];
void add_array(int data)
{
    array[count] = data;
    count++;
}
void print_array()
{
    int i;
    for(i = count-1; i >= 0; i--)
    {
        printf("%d ",array[i]);
    }
}

void main()
{
    int choice,num;
    struct node *root = NULL;

    while(1)
    {
        printf("\n\n");
        printf("1.Insert\n");
        printf("2.Inorder Traversal\n");
        printf("3.Preorder Traversal\n");
        printf("4.Postorder Traversal\n");
        printf("5.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the number to be inserted : ");
                scanf("%d",&num);
                root = insert(root,num);
            break;

            case 2:
                inorder(root);
            break;

            case 3:
                preorder(root);
            break;

            case 4:
                postorder(root);
            break;

            case 5:
                exit(1);

            default:
                printf("\nWrong choice\n");
            break;
        }
    }
}

struct node *insert(struct node *root, int ikey)
{
    struct node *tmp,*par,*ptr;

    int found = 0;

    ptr = root;
    par = NULL;

    while(ptr != NULL)
    {
        if(ikey == ptr->info)
        {
            found = 1;
            break;
        }
        par = ptr;
        if(ikey < ptr->info)
        {
            if(ptr->left_flag == 0)
                ptr = ptr->left;
            else
                break;
    }
        else
        {
            if(ptr->right_flag == 0)
                ptr = ptr->right;
            else
                break;
        }
    }

    if(found)
        printf("\nDuplicate key");

    else
    {
        tmp = malloc(sizeof(struct node));
        tmp->info=ikey;
        tmp->left_flag = 1;
        tmp->right_flag = 1;
        if(par == NULL)
        {
            root = tmp;
            // printf("root created");
            create_header(tmp);
            tmp->left = head;
            tmp->right = head;
            // printf("root created successful");
        }
        else if(ikey < par->info)
        {
            tmp->left = par->left;
            tmp->right = par;
            par->left_flag = 0;
            par->left = tmp;
        }
        else
        {
            tmp->left = par;
            tmp->right = par->right;
            par->right_flag = 0;
            par->right = tmp;
        }
    }
    return root;
}

struct node *in_succ(struct node *ptr)
{
    if(ptr->right_flag == 1)
        return ptr->right;

    else
    {
        ptr = ptr->right;
        while(ptr->left_flag == 0)
            ptr = ptr->left;
        return ptr;
    }
}

struct node *in_pred(struct node *ptr)
{
    if(ptr->left_flag == 1)
        return ptr->left;
    
    else
    {
        ptr = ptr->left;
        while(ptr->right_flag == 0)
            ptr = ptr->right;
        return ptr;
    }
}

void inorder(struct node *root)
{
    struct node *ptr;
    if(root == NULL)
    {
        printf("Tree is empty");
        return;
    }

    ptr = root;
    while(ptr->left_flag == 0)
        ptr=ptr->left;

    while(ptr != head)
    {
        printf("%d ",ptr->info);
        ptr = in_succ(ptr);
    }
}

void preorder(struct node *root)
{
    struct node *ptr;
    if(root == NULL)
    {
        printf("Tree is empty");
        return;
    }
    ptr = root;

    while(ptr != head)
    {
        printf("%d ",ptr->info);
        if(ptr->left_flag == 0)
            ptr = ptr->left;
        
        else if(ptr->right_flag == 0)
            ptr = ptr->right;
        
        else
        {
            while(ptr != head && ptr->right_flag == 1)
                ptr = ptr->right;
            
            if(ptr != head)
                ptr = ptr->right;
        }
    }
}

void postorder(struct node *root)
{
    struct node *ptr;
    if(root == NULL)
    {
        printf("Tree is empty");
        return;
    }
    ptr = root;

    while(ptr != head)
    {
        add_array(ptr->info);
        if(ptr->right_flag == 0)
            ptr = ptr->right;
        
        else if(ptr->left_flag == 0)
            ptr = ptr->left;
        
        else
        {
            while(ptr != head && ptr->left_flag == 1)
                ptr = ptr->left;
            
            if(ptr != head)
                ptr = ptr->left;
        }
    }
    print_array();
}