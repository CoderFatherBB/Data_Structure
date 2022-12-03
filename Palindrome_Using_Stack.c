#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

int top = -1;
int top2 = -1;
char stack[MAX];
char stack2[MAX];


int stackFull() // Checks if Stack is Full 
{    
    if(top >= MAX - 1)
        return TRUE;
    
    else
        return FALSE;
}

int stackFull2() // Checks if Stack is Full 
{    
    if(top2 >= MAX - 1)
        return TRUE;
    
    else
        return FALSE;
}
 
int stackEmpty() // Checks if Stack is Empty 
{
    if(top == -1)
        return TRUE;
 
    else
        return FALSE;
}

int stackEmpty2() // Checks if Stack is Empty 
{
    if(top2 == -1)
        return TRUE;
 
    else
        return FALSE;
}

void push(char element)
{
    if (stackFull())
        printf("Stack is Full \n");

    else 
        stack[top + 1] = element;
        top++;
        
}

void push2(char element)
{
    if (stackFull2())
        printf("Stack is Full \n");

    else 
        stack2[top2 + 1] = element;
        top2++;
        
}

char pop()
{
    if (stackEmpty())
        printf("Stack is Empty \n");

    else 
        top = top - 1;
        return stack[top + 1];

}

char pop2()
{
    if (stackEmpty2())
        printf("Stack is Empty \n");

    else 
        top2 = top2 - 1;
        return stack2[top2 + 1];

}

void str_palindrome(char str[])
{
    int i;
    char element = 0;
    int len;
    len = strlen(str);
     
    for(i = 0; i < len; i++)
    {
        push(str[i]);
    }

    for(i = 0; i < len; i++)
    {
        if(str[i] == pop())
        {
            element ++;  
        }

    }
    if(len == element )
        printf("This string is palindrome\n ");
    
    else
        printf("The string is not palindrome");
}

void str_reverse(char str[])
{
    int i;
    int len;
    len = strlen(str);
     
    for(i = 0; i < len; i++)
    {
        push(str[i]);
    }
        
    for(i = 0; i < len; i++)
    {
        str[i] = pop();
    }
    str[i] = '\0';
    // printf("Reversed string is: %s\n",str);
}

void str_concat(char str[] , char str2[])
{
    int i;
    int len,len2;
    len  = strlen(str);
    len2 = strlen(str2);
    for(i = 0; i < len; i++)
    {
        push(str[i]);
    }

    for(i = 0; i < len2; i++)
    {
        push(str2[i]);
    }

    for(i = 0; i < len + len2; i++)
    {
       str[i] = pop();
    }
    str[i] = '\0';
    str_reverse(str);
    printf("Concated String is: %s\n",str);
}

void str_compare(char str[] , char str2[])
{
    int i, flag=0;
    int len, len2;
    str_reverse(str);
    len = strlen(str);

    str_reverse(str2);
    len2 = strlen(str2);
    
    for(i = 0; i < len; i++)
    {
        push(str[i]); 
    }

    for(i = 0; i < len2; i++)
    {
        push2(str2[i]);
    }


    for(i = 0 ; str[i] != '\0' || str2[i] !='\0' ; i++)
    {
        str[i] = pop();
        str2[i] = pop2();
        if(str[i] != str2[i])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("Strings are Same !");

    else 
    {
        if(len > len2) // str[i] > str2[i]
        {
            printf("String 2 is small\nStrings are not same !");
        }
        else if(len < len2) // str[i] < str2[i]
        {
            printf("String 1 is small\nStrings are not same !");
        }
        else
        {
            printf(" Strings are not same !");
        }
    }
        
}
    

int main()
{
    int option,len;
    char Stack[MAX];
    char str[MAX];
    char str2[MAX];

    printf("Enter Option for particular Operation to be performed :\n1. Palindrome \n2. String Reverse \n3. String Concatenate \n4. String Compare \n5. Exit");
    while(1)
    {
        printf("\nEnter Option : ");
        scanf("%d",&option);
        printf("\n\n"); 
        switch (option)
        {
            case 1:
                printf("Operation Performing is Palindrome \n"); 
                printf("Enter a string : ");
                scanf("%s",str);
                str_palindrome(str);
                printf("\n\n");  
            break;
            
            case 2:
                printf("Operation Performing is String reverse \n");
                printf("Enter a string : ");
                scanf("%s",str);
                str_reverse(str);
                printf("Reversed string is: %s\n",str);
                printf("\n\n"); 
            break;

            case 3:
                printf("Operation Performing is String Concatenation \n");            
                printf("Enter a string  1 : ");
                scanf("%s",str);   
                printf("Enter a string  2 : ");
                scanf("%s",str2);  
                str_concat(str ,str2);
                printf("\n\n");  
            break;

            case 4:
                printf("Operation Performing is String Compare \n");    
                printf("Enter a string  1 : ");
                scanf("%s",str);   
                printf("Enter a string  2 : ");
                scanf("%s",str2);  
                str_compare(str ,str2);
                printf("\n\n");  
            break;     

            case 5:
                printf("Code Exited");            
            exit(0);

            default: printf("Option not avalible ! \n");
            break;
        }
    } 
    return 0;
}