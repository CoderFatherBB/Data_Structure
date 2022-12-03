// Adjascency List representation in C
#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int vertex;
    struct node* next;
};
struct node* createNode(int);

struct Graph 
{
    int numVertices;
    struct node** adjLists;
};


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
        printf("%d ",ptr->vertex);
        if(ptr->next!=NULL)
            insert_queue(ptr->vertex);
    }
    printf("\n");
}


// Create a node
struct node* createNode(int v) 
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
struct Graph* createAGraph(int vertices) 
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));

    int i;
    for (i = 1; i <= vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int s, int d) 
{
    // Add edge from s to d
    struct node* newNode = createNode(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;

    // Add edge from d to s
    newNode = createNode(s);
    newNode->next = graph->adjLists[d];
    graph->adjLists[d] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) 
{
    int v;
    for (v = 1; v <= graph->numVertices; v++) 
    {
        struct node* temp = graph->adjLists[v];
        printf("\n Vertex %d\n: ", v);
        while (temp) {
        printf("%d -> ", temp->vertex);
        temp = temp->next;
        }
        printf("\n");
    }
}

void main() 
{
    int n, v1, v2;
    int ch;

    printf("Enter Number of vertex : ");
    scanf("%d", &n);

    struct Graph* graph = createAGraph(n);

    printf("Do you want to enter a edge (1/0) : ");
    scanf("%d", &ch);
    while(ch == 1)
    {
        printf("Want a edge between v1 & v2 : Where : ");
        printf("\nv1 = ");
        scanf("%d", &v1);
        printf("v2 = ");
        scanf("%d", &v2);

        addEdge(graph, v1, v2);

        printf("Do you want to enter a edge (1/0) : ");
        scanf("%d", &ch);
    }

    printGraph(graph);
    level_trav(graph);
}