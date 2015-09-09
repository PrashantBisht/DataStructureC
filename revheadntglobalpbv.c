#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* next;
};

void Print(struct Node*);
struct Node* Insert(struct Node*,int);//pbv otherwise Node** pass by ref
struct Node* Reverse(struct Node*);


struct Node* Reverse(struct Node* head)
{
    struct Node *temp,*prev,*next,*current;
    current=head;//head is global
    prev=NULL;
    while(temp!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;//came out of loop prev pointing to last node

}

struct Node* Insert(struct Node* head,int data)
{

struct Node* temp =(struct Node*)malloc(sizeof(struct Node));
temp->data=data;
temp->next=NULL;
if(head==NULL)head=temp;
else{
    struct Node* temp1=head;
    while(temp1->next!=NULL)temp1=temp1->next;
    temp1->next=temp;
}
return head;
}

void Print(struct Node* head){
while(head!=NULL)
    {
    printf("%d",head->data);
    head=head->next;
    }
}


int main()
{

    struct node* head=NULL;//local variable
    head=Insert(head,2);//since head is loc we need to pass it as a arg to fmc
    head=Insert(head,4);
    head=Insert(head,6);
    head=Insert(head,8);
    Print(head);
    head=Reverse(head) ;
    Print(head);
}


