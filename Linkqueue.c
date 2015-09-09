#include<memory.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*link;
}
;
void addq(struct node**,struct node**,int);
int delq(struct node**,struct node**);
int count(struct node*);
int delq(struct node**,struct node **);
void q_display(struct node*);

int main()
{
    struct node *front,*rear;
    int item;
    front=rear=NULL;

    addq(&front,&rear,11);
    addq(&front,&rear,12);
    addq(&front,&rear,13);
    addq(&front,&rear,14);
    addq(&front,&rear,15);
    addq(&front,&rear,16);
    addq(&front,&rear,17);
    q_display(front);
    printf("\n No. of items in the queue %d",count(front));
    printf("\nItems extracted from the queue ");
    item=delq(&front,&rear);
    printf("\n%d",item);
    item=delq(&front,&rear);
    printf("\n%d",item);
    item=delq(&front,&rear);
    printf("\n%d",item);
    printf("\n");
    q_display(front);
    printf("\n No. of items in the queue %d",count(front));
    }
void addq(struct node**f,struct node**r,int item)
{
    struct node*q;
     q=(struct node *)malloc(sizeof(struct node));
     q->data=item;
     q->link=NULL;
     if (*f == NULL)//f=&head where  head is also a pointer therefore *f=*(&head) >>which gives actual head which is address of first  node if its is null list empty
        {
            *f=q;//head=q head and q now both points to same block   or head now points to q q has been added
            printf("%d first node added sucessfully\n",*q);
        }
     else
        (*r)->link=q;//why not r->link??? doubt r=&rear  rear=&last node  *r=*(&lastnode)>>lastnode therefore lastnode>>link=q

    *r=q;
    printf("%d node added sucessfully\n",*q);
     }
int delq(struct node**f,struct node **r)
{
    struct node*q;
    int item;
    if(*f==NULL)
    {
        printf("queue is empty");

    }
    else
        {
         q=*f;
    item=q->data;
    *f=q->link;
    free(q);
    /*if on deletion queue has become empty*/
      if(*f==NULL)
    {
        *r=NULL;
    }

    return(item);
    }
}

void q_display(struct node*q)
{
    printf("\n front->");
    while(q!=NULL)
    {
       //if(q->link=NULL)
          // printf("<-rear");
        printf("\t%d",q->data);
        q=q->link;
    }
   // q=q->link;
    //printf("\t%d",q->data);
    printf("\t<--rear");
    printf("\n");
}

int count(struct node*q)
{
    int c=0;
    while(q!=NULL)
    {
        q=q->link;
        c++;
    }
    return (c);
}

