#include<stdio.h>
#include<stdlib.h>
int N;
struct stack
{
    int *data;
    int top;
    
};
void init(struct stack *S)
{
    S->data=(int*)malloc(N*sizeof(int));
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
void push(struct stack *S,int x)
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
    printf("Stack is Empty\n");
    return -1;
}
void printstack(struct stack *S)
{
    printf("The Stack is: \n");
    for(int i=0;i<=S->top;i++)
        printf(" %d",S->data[i]);
    printf("\n");
}
int main()
{
    struct stack s;
    printf("Enter the capacity of the stack:\n");
    scanf("%d",&N);
    init(&s);
    int x=-1,val;
    while(x!=0)
    {
        printf("Press 1 to push an element\n      2 to pop\n      3 to print the stack\n      0 to exit:");
        scanf("%d",&x);
        switch(x)
        {
            case 1:            
                printf("Enter the number to  be pushed\n");
                scanf("%d",&val);
                push(&s,val);
                break;
            
            case 2:            
                val=pop(&s);
                if(val!=-1)
                    printf("Value popped: %d\n",val);
                break;
            
            case 3:
                printstack(&s);
                break;
            case  0:
                break;
            default :
                printf("Wrong choice\n");
            
        }

    }
    return 0;
}
    
