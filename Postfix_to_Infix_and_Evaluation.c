#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define MAX 50
char postfix[MAX];
char stack[MAX][MAX];
int stackn[MAX];
int top = -1;
int topn = -1;



char *pop()
{
    if(top == -1 )
    {
        printf("\nStack underflow \n");
        exit(2);
    }
    return (stack[top--]);
}
void push(char *str)
{
    if(top == (MAX - 1))
    {
        printf("\nStack overflow\n");
        exit(1);
    }
    top++;
    strcpy(stack[top], str);
}



void pushn(int item)
{
    if(topn == (MAX - 1))
    {
        printf("Stack Overflow\n");
        return;
    }
    topn++;                              
    stackn[topn] = item;    
}
int popn()
{
    if(topn == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return(stackn[topn--]);
}



void postfix_to_infix()
{
    int i;
    char operand1[MAX], operand2[MAX], opreator, operand;
    char temp[2], str[2], open[2] = {"("}, close[2] = {")"};
    char strin[MAX];

    for(i = 0; i <= strlen(postfix); i++)
    {
        if(postfix[i] >= 'a' && postfix[i] <= 'z')
        {
            operand = postfix[i];
            str[0] = operand;
            str[1] = '\0';
            push(str);
        }

        else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            opreator = postfix[i];
            temp[0] = opreator;
            temp[1] = '\0';

            strcpy(operand2, pop());
            strcpy(operand1, pop());
            strcpy(strin, open);
            strcat(strin, operand1);
            strcat(strin, temp);
            strcat(strin, operand2);
            strcat(strin, close);

            push(strin);
        }
    }
    printf("Infix Expression : ");
    puts(stack[top]);
}



void evaluate()
{
    int num, i, a , b, ans;
    printf("\n");
    for(i = 0; i <= strlen(postfix); i++)
    {
        if(postfix[i] >= 'a' && postfix[i] <= 'z')
        {
            printf("Enter value for %c : ", postfix[i]);
            scanf("%d", &num);
            pushn(num);
        }

        else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {        
            a = popn();       
            b = popn();         
            switch(postfix[i])
            {
                case '+':
                    ans = b + a;
                break;
                
                case '-':
                    ans = b - a;
                break;
                
                case '*':
                    ans = b * a;
                break;
                
                case '/':
                    ans = b / a;
                break;
                
                default:
                    ans = 0;
            }
            pushn(ans);
        }
    }
    printf("\nAnswer of the equation is : %d", popn());
}



void main()
{
    printf("Enter the postfix expression : ");
    gets(postfix);
    postfix_to_infix();
    evaluate();
}