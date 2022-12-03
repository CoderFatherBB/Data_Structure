#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct node
{
    struct node *left;
    int info;
    struct node *right;
};

struct node *insert(struct node *root, int ikey );
void level_trav(struct node *root);
void display(struct node *ptr,int level);
void reheapify(struct node * ptr);
void printLevel(struct node * root, int level);
int heightOfTree(struct node * root);
void heapify(struct node * heap);


struct node *queue[MAX];
int front=-1,rear=-1;
//Functions for implementation of queue
void insert_queue(struct node *item)
{
    if(rear==MAX-1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if(front==-1)  //If queue is initially empty
        front=0;
    rear=rear+1;
    queue[rear]=item ;
}

struct node *del_queue()
{
    struct node *item;
    if(front==-1 || front==rear+1)
    {
        printf("Queue Underflow\n");
        return 0;
    }
    item=queue[front];
    front=front+1;
    return item;
}

int queue_empty()
{
    if(front==-1 || front==rear+1)
        return 1;
    else
        return 0;
}

void main()
{
    struct node *root=NULL, *ptr;
    int choice,k;

    while(1)
    {
        printf("\n");
        printf("1.Insert\n");
        printf("2.Level order traversal\n");
        printf("3.Display\n");
        printf("4.Heap\n");
        printf("5.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the key to be inserted : ");
                scanf("%d",&k);
                root = insert(root, k);
            break;

            case 2:
                level_trav(root);
            break;

            case 3:
                printf("\n");
                display(root,0);
                printf("\n");
            break;

            case 4:
                heapify(root);
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
    struct node *new,*ptr2,*ptr;

    ptr = root;
    ptr2 = NULL;

    while( ptr!=NULL)
    {
        ptr2 = ptr;
        if(ikey < ptr->info)
            ptr = ptr->left;
        else if( ikey > ptr->info )
            ptr = ptr->right;
        else
        {
            printf("\nDuplicate key");
            return root;
        }
    }

    new = malloc(sizeof(struct node));
    new->info=ikey;
    new->left=NULL;
    new->right=NULL;

    if(ptr2==NULL)
        root=new;
    else if( ikey < ptr2->info )
        ptr2->left=new;
    else
        ptr2->right=new;

    return root;
}

void display(struct node *ptr,int level)
{
    int i;
    if(ptr == NULL )
        return;
    else
    {
        display(ptr->right, level+1);
        printf("\t\n");
        for (i=0; i<level; i++)
            printf("    ");
        printf("%d", ptr->info);
        display(ptr->left, level+1);
    }
}

// arring data in tree.
void reheapify(struct node * ptr)
{
    struct node *ptr2;
    int V1,V2,temp;

    V1 = ptr->info;

    while(ptr->left != NULL && ptr->right != NULL){
        if (ptr->left->info < ptr->right->info){
            ptr2 = ptr->left;
        }
        else if (ptr->left->info > ptr->right->info){
            ptr2 = ptr->right;
        }

        V2 = ptr2->info;

        if (V1 <= V2){
            return;
        } else {
            temp = ptr->info;
            ptr->info = ptr2->info;
            ptr2->info = temp;

            ptr = ptr2;
            V1 = ptr->info;
        }
    }
}

void printLevel(struct node * root, int level)
{
    if (root == NULL) return;
    //if (level == 1) printf("%d ",root -> info);
    if (level == 0) reheapify(root);
    else if (level > 0){
        printLevel(root -> left, level-1);
        printLevel(root -> right, level-1);
    }
}

int heightOfTree(struct node * root)
{
    if (root == NULL) return 0;
    else{
        int leftHieght = heightOfTree(root -> left);
        int rightHeight = heightOfTree(root -> right);

        // printf("%d %d",leftHieght, rightHeight);
        if (leftHieght > rightHeight) return leftHieght+1;
        else return rightHeight+1;
    }
}

void heapify(struct node * heap)
{
    int height = heightOfTree(heap);
    printf("%d",height);

    for(int i = height; i >= 0; i--) printLevel(heap,i);
}


void level_trav(struct node *root)
{
    struct node *ptr = root;

    if( ptr==NULL )
    {
        printf("Tree is empty\n");
        return;
    }

    insert_queue(ptr);

    while( !queue_empty() ) //Loop until queue is not empty
    {
        ptr=del_queue();
        printf("%d ",ptr->info);
        if(ptr->left!=NULL)
            insert_queue(ptr->left);
        if(ptr->right!=NULL)
            insert_queue(ptr->right);
    }
    printf("\n");
}
