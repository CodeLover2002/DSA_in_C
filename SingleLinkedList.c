#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    
};
int con=0;
struct node *head=NULL,*tail=NULL;
void init(int d, struct node *p)
{
    p->data=d;
    p->next=NULL;    
    
}
void createlist()
{
    int dt;
    head=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be stored inside the first node of the linked list\n");
    scanf("%d",&dt);
    init(dt,head);
    tail=head;
    con++;
    printf("Your list has been created.\n");
}
void AddAtBeg(struct node*ptr)
{
    ptr->next=head;
    head=ptr;
    con++;   
}
void AddAtEnd(struct node*ptr)
{
    tail->next=ptr;
    tail=ptr;
    con++;   
}
void addnode()
{
    int ch,dt;
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be stored inside the node of the linked list\n");
    scanf("%d",&dt);
    init(dt,ptr);
    if(head==NULL)
    {
        head=ptr;
        tail=head;
        con++;
        return;
    }
    printf("Press 1 to add node at the beginning\n      2 to add node at the end\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            AddAtBeg(ptr);
            break;
        case 2:
            AddAtEnd(ptr);
            break;
        default:
            printf("Wrong choice\n");   
    }
    
}
struct node *NodeAtPosition(int n)
{
    if(n==1||n>con)
        return NULL;
    if(n==2)
        return head;
    struct node *ptr=head;
    for(int i=1;i<n-1;i++)
    {
        ptr=ptr->next;   
    }
    return ptr;
}
void insertnode()
{
    int ch,dt,pos;
    struct node *ptr,*ptr2;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be stored inside the node of the linked list\n");
    scanf("%d",&dt);
    init(dt,ptr);
    printf("Enter the position where the node is to be inserted\n");
    scanf("%d",&pos);
    if(pos==1)
        AddAtBeg(ptr);
    else if(pos>con)
        AddAtEnd(ptr);
    else
    {
       ptr2=NodeAtPosition(pos);
       ptr->next=ptr2->next;
       ptr2->next=ptr;
       con++;
    }   
}
void DelAtBeg()
{
    struct node *ptr;
    ptr=head;
    head=head->next;
    free(ptr);
    if(head==NULL)
        tail=head;
    con--;
    
}
void DelAtEnd()
{   
    struct node *ptr=head;
    if(head==tail)
    {   
        free(head);
        head=NULL;
        tail=NULL;
        con--;    
        return;
    }
    while(ptr->next!=tail)
    {
        ptr=ptr->next;
    }
    ptr->next=NULL;
    free(tail);
    tail=ptr;
    con--;
}
void DelAtPos()
{   int pos;
    struct node *ptr,*ptr2;
    printf("Enter the position of the node to be deleted\n");
    scanf("%d",&pos);
    if(pos==1)
        DelAtBeg();
    else if(pos==con)
        DelAtEnd();
    else if(pos>con)
        printf("Not possible as there are no nodes with position %d\n",pos);
    else
    {
        ptr=NodeAtPosition(pos);
        ptr2=ptr->next;
        ptr->next=ptr2->next;
        free(ptr2);
        con--;
    } 
    
}
void deletenode()
{   
    if(head==NULL)
    {    
        printf("The linked list is empty.\n");
        return;
    }
    int ch;
    printf("Press 1 to delete node at the beginning\n      2 to delete node at the end\n      3 to delete node at a particular position\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            DelAtBeg();
            break;
        case 2:
            DelAtEnd();
            break;
        case 3:
            DelAtPos();
            break;
        default:
            printf("Wrong choice\n");   
    }
}
void printlist()
{   
    struct node *p=head;
    int c=0;
    if(head==NULL)
    {   
        printf("The list is empty.\n");
        return;
    }
    else
    {
        while(p->next!=NULL)
        {
            c++;
            printf("Node: %d    Data:   %d\n",c,p->data);
            p = p->next;
        }
        c++;
        printf("Node: %d    Data:   %d\n",c,p->data);
    
    }
}
int main()
{
    int ch=-1;
    while(ch!=0){
    printf("Press 1 to create a linkedlist\n      2 to add a node\n      3 to delete a node\n      4 to insert a node at the desired position\n      5 to print the list\n      0 to exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            createlist();
            break;
        case 2:
            addnode();
            break;
        case 3:
            deletenode();
            break;
        case 4:
            insertnode();
            break;
        case 5:
            printlist();
            break;
        case 0:
            break;
        default:
            printf("Wrong choice.\n");    
    }
    }
}