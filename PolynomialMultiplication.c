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
    printf("Enter the terms of the polynomial expression in ascending order of the exponents:-\n");
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
struct node* selsort(struct node *head,struct node *tail)
{
    struct node *i,*j,*max;
    int temp;
    for(i=head;i!=tail;i=i->link)
    {   
        max=i;
        for(j=i->link;j!=NULL;j=j->link)
        {
            if(j->exp>max->exp)
            {
                max=j;
            }    
        }
        if(max!=i)
        {
            temp=i->coef;
            i->coef=max->coef;
            max->coef=temp;
            temp=i->exp;
            i->exp=max->exp;
            max->exp=temp;
        }
        
    }
    return head;
}
struct node *mult(struct node *p1,struct node *p2)
{
    struct node *result=NULL,*ptr=NULL,*pb2=p2;
    int sum;
    while(p1!=NULL)
    {   
        p2=pb2;
        while(p2!=NULL)
        {   
            ptr=addnode(ptr);
            if(result==NULL)
                result=ptr;
            init(ptr,p1->coef*p2->coef,p1->exp+p2->exp);
            p2=p2->link;
        }
        p1=p1->link;
    } 
    result=selsort(result,ptr);
    pb2=result;
    while(pb2!=ptr)
    {
        if(pb2->exp==pb2->link->exp)
        {
            pb2->coef=pb2->coef+pb2->link->coef;
            p1=pb2->link;
            pb2->link=pb2->link->link;
            free(p1);
        }
        pb2=pb2->link;
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
    struct node *m=NULL;
    printf("The resultant polynomial expression on multiplying both is:\n");
    m=mult(pe1,pe2);
    printlist(m);    
    
    

}