
#include<memory.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*link;
}
;
void push(struct node**,int);
int pop(struct node**);
void stack_display(struct node*);
int count(struct node *);

int main()
{
    struct node *top;
    int item;
    top=NULL;
    push(&top,11);
    push(&top,12);
    push(&top,13);
    push(&top,14);
    push(&top,15);
    push(&top,16);
    stack_display(top);
    printf("\n");
    printf("No. of items in the stack %d",count(top));
    printf("\n Items extreacted from stack=%d",pop(&top));
    printf("\n Items extreacted from stack=%d",pop(&top));
    printf("\n Items extreacted from stack=%d",pop(&top));
    printf("\n No. of items in the stack %d",count(top));
    stack_display(top);
}
void push(struct node**s,int item)
{
    struct node *q;/*creating a node of type node,node will point to(store the address of other node)other node of type node >_<*/
    q = malloc(sizeof(struct node));/*allocating space*/
    q->data=item;
    q->link=*s;/*new node pointing to place here *s(top=address of top element) **s(address of top as we want change in top we have to pass its reference to reflect changes everywhere) was pointing earlier*/
    *s=q;/*top points to newly created node*/
}
int pop(struct node**s)
{
    int item;
    struct node*q;
    if(*s==NULL)
    {
        printf("Empty Stack");
    }
    else{
        q=*s;/*now q pointing to top element*/
        item=q->data;/* or (*s)->data*/
        *s=q->link;/*now pointing to second element as first is going to be popped out*/
        free(q);
        return(item);
    }
}
void stack_display(struct node*q)
{
    printf("\n");
    while(q!=NULL)
    {

        printf("%d",q->data);
        q=q->link;
        printf("\n");
    }
    printf("\n");

    }

int count(struct node *q)
{
    int c=0;
    while(q!=0)
    {
        q=q->link;
        c++;
    }
    return c;
}








