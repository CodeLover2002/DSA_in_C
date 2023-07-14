#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int coef;
    int exp;
    struct node *link;
};
int c=0;
void init(struct node *pe,int cf,int ex)
{
    pe->coef=cf;
    pe->exp=ex;
    pe->link=NULL;  
}
int createlist(struct node **head)
{
    int n,ex;
    c++;
    int cf;
    struct node *ptr,*pe=NULL;
    printf("Enter the number of terms of the polynomial expression %d:\n",c);
    scanf("%d",&n);
    printf("Enter the terms of the polynomial expression in sorted order.\n\n");
    for(int i=1;i<=n;i++)
    {
        printf("Enter the coefficient and exponent of term %d of the polynomial expression : \n",i);
        scanf("%d%d",&cf,&ex);
        ptr=(struct node*)malloc(sizeof(struct node));
        init(ptr,cf,ex);
        if(pe!=NULL)
        {   
            pe->link=ptr;
            pe=ptr;
        }
        else
        {
            pe=ptr;
            *head=ptr;
        }
        
    }
    return n;
    
}
struct node* addnode(struct node *prev)
{
    struct node *next=(struct node *)malloc(sizeof(struct node));
    if(prev!=NULL)
        prev->link=next;
    return next;
}
struct node *addition(struct node *p1,struct node *p2)
{
    struct node *result=NULL,*ptr=NULL;
    int sum;
    while(p1!=NULL && p2 !=NULL)
    {
        ptr=addnode(ptr);
        if(result==NULL)
            result=ptr;        
        if(p1->exp<p2->exp)
        {
            init(ptr,p1->coef,p1->exp);
            p1=p1->link;
        }
        else if(p2->exp<p1->exp)
        {
            init(ptr,p2->coef,p2->exp);
            p2=p2->link;
        }
        else
        {
            sum=p1->coef+p2->coef;
            init(ptr,sum,p1->exp);
            p1=p1->link;
            p2=p2->link;       
        }
    
    }
    if(p1==NULL)
    {
        while(p2!=NULL)
        {
            ptr=addnode(ptr);
            init(ptr,p2->coef,p2->exp);
            p2=p2->link;   
        }
    }
    if(p2==NULL)
    {
        while(p1!=NULL)
        {
            ptr=addnode(ptr);
            init(ptr,p1->coef,p1->exp);
            p1=p1->link;   
        }
    }
        
        return result;
    
}
void printlist(struct node *p)
{   
    int c=0;
    struct node *head=p;
    if(p==NULL)
    {   
        printf("The list is empty.\n");
        return;
    }
    else
    {
        while(p!=NULL)
        {
            
            if(p==head && p->coef!=0)
            {   if(p->exp==0)
                    printf(" %d ",p->coef);
                else
                    printf(" %dx^%d",p->coef,p->exp);
            }
            else if(p->coef!=0)
            {
                if(p->coef>0)
                    printf(" +%dx^%d ",p->coef,p->exp);
                else
                   printf(" %dx^%d",p->coef,p->exp); 
            
            }         
            p = p->link;
        }
      printf("\n");  
    }
}
int main()
{
    struct node *pe1=NULL,*pe2=NULL;
    int c1,c2;
    c1=createlist(&pe1);
    printf("The polynomial expression 1 is:\n");
    printlist(pe1);
    c2=createlist(&pe2);
    printf("The polynomial expression 2 is:\n");
    printlist(pe2);
    struct node *add=NULL;
    printf("The resultant polynomial expression on adding both is:\n");
    add=addition(pe1,pe2);
    printlist(add);    
    
    

}