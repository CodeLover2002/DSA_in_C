#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
struct stack
{
    char *data;
    int top;
    
};
void init(struct stack *S)
{
    S->data=(char*)calloc((N+1),sizeof(char));
    S->top=-1;
}
int isFull(struct stack *S)
{
    if(S->top==N-1)
        return 1;
    return 0;
}
int isEmpty(struct stack *S)
{
    if(S->top==-1)
        return 1;
    return 0;
}
void push(struct stack *S,char x)
{
    if(!isFull(S))
        S->data[++(S->top)]=x;
    else
        printf("Stack is Full\n");
}
int pop(struct stack *S)
{
    if(!isEmpty(S))
        return S->data[S->top--];
    return 0;
}
void print(struct stack *S)
{
    printf("The postfix expression is: \n");
    printf("%s",S->data);
    printf("\n");
}
int priority(char c)
{
    if(c=='^') 
        return 3;
    if(c=='*'||c=='/'||c=='%')
        return 2;
    if(c=='+'||c=='-')
        return 1;
    if(c=='('||c==')')
        return 0;

}
int isOperand(char c)
{
    if(c=='^'||c=='*'||c=='/'||c=='%'||c=='+'||c=='-'||c=='('||c==')')
        return 0;
    else
        return 1;

}
void InToPo(char *inf,struct stack *op,struct stack *pf)
{   int x;
    for(int i=0;i<strlen(inf);i++)
    {
        if(isOperand(inf[i]))
            push(pf,inf[i]);
        else if(inf[i]=='(')
            push(op,inf[i]);
        else if(inf[i]==')')
        {
            while(op->data[op->top]!='(')
                push(pf,(char)pop(op));
            x=pop(op);
        }
        else
        {
            while(!isEmpty(op) && priority(op->data[op->top])>=priority(inf[i])) 
                push(pf,pop(op));
            push(op,inf[i]);
        }
    }
    while(!isEmpty(op))
        push(pf,pop(op));
}
int main()
{
    struct stack *pf,*op;
    char inf[N];
    pf=(struct stack*)malloc(sizeof(struct stack));
    op=(struct stack*)malloc(sizeof(struct stack));
    init(pf);
    init(op);
    printf("Enter a valid Infix expression: ");
    scanf("%[^\n]s",inf);
    InToPo(inf,op,pf);
    print(pf); 
    free(pf);
    free(op);
}