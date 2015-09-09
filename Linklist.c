#include<memory.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*link;
}
;
/*void addatbeg(struct node**,int);
int (struct node**);
void stack_display(struct node*);
int count(struct node *);
*/
int main()
{
    struct node *p;
    p=NULL;
    append(&p,11);
    append(&p,12);
    append(&p,13);
    append(&p,14);
    append(&p,15);
    append(&p,16);
    append(&p,17);
    append(&p,18);
    append(&p,19);
    append(&p,20);
    display(p);
    printf("No. of items in the List %d",count(p));
    printf("\n");
    addatbeg(&p,12);
    addatbeg(&p,111);
    addatbeg(&p,112);
    display(p);
    printf("No. of items in the List %d",count(p));
    printf("\n");
    addafter(p,7,90);
    addafter(p,2,1);
    addafter(p,1,99);
    display(p);
    printf("No. of items in the List %d",count(p));
    delete_1(&p,99);
    delete_1(&p,111);
    delete_1(&p,12);
    display(p);
    printf("\n No. of elements in the linked list=%d",count(p));
}
append(struct node**q,int num)
{/* **q menas q is a pointer to a pointer q=&p where p is also a pointer*/
    struct node *temp,*r;/*creating a node of type node,node will point to(store the address of other node)other node of type node >_<*/
    temp=*q;//*q=*(&p) which is p so now temp=p
    if(*q==NULL)
    {

        temp=malloc(sizeof(struct node));//malloc returns address of the memory block created in the heap
        temp->data=num;//temp=&memoryblockreturnedbymalloc
        temp->link=NULL;
        *q=temp;//q=&p(ie. head) *q=*(&p).>>> p so p=temp now ie p points to temp now temp is the first node
    }
    else
        {
        temp=*q;
        while(temp->link!=NULL)//at teamp->link=Null equation fails
        temp=temp->link;
          r=malloc(sizeof(struct node));
          r->data=num;
          r->link=NULL;
          temp->link=r;
        }
    }

addatbeg(struct node**q,int num)
{
    struct node*temp;
    temp=malloc(sizeof(struct node));
    temp->data=num;
    temp->link=*q;
    *q=temp;
}
addafter(struct node*q,int loc,int num)
{
    struct node *temp,*r;
    int i;
    temp=q;//Note not temp=*q
    for(i=0;i<=loc;i++)
    {
        temp=temp->link;
        if(temp==NULL)
        {
            printf("There are less than %d elements in the list",loc);

        }
    }
    r=malloc(sizeof(struct node));
    r->data=num;
    r->link=temp->link;
    temp->link=r;
}
display(struct node*q)
{
    printf("\n");
    while(q!=NULL)
    {
        printf("%d",q->data);
        q=q->link;
        printf("\n");
    }

}
count(struct node*q)
{
    int c=0;
    while(q!=NULL)
    {
        q=q->link;
        c++;
    }
    return c;
}

   delete_1(struct node**q,int num)
   {

       struct node*old,*temp;//analogy int k
       temp=*q;//k=q
       while(temp!=NULL)
       {
           if(temp->data==num)
           {
             if(temp==*q)
             {
                 *q=temp->link;
                 free(temp);
                 return;
             }
             else
                {
                    old->link=temp->link;
                    free(temp);
                    return;

                }
           }
           else
           {

               old=temp;
               temp=temp->link;
           }
           }
           printf("Element %d not found",num);
       }

