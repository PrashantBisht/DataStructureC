#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* next;};

struct Node* head;//Note head here is declared as global variable
void Print();
void Insert(int,int);
void Reverse();

int main(){
    head=NULL;
    Insert(10,1);//2
    Insert(11,2);//2,3
    Insert(12,3);//423
    Insert(13,4);
    Print();
    Reverse();
    Print();
}

void Reverse()
{
    struct Node *temp,*prev,*next,*current;
    current=head;//head is global
    prev=NULL;
    while(current!=NULL)//jugaad to not to loose next node's address after setting its next to prev
    {
        next=current->next;
        current->next=prev;//(*current).next=prev;
        prev=current;
        current=next;
    }
    head=prev;//came out of loop prev pointing to last node

}
void Insert(int data,int n){
struct Node* temp1=(struct Node*)malloc(sizeof(struct Node));
temp1->data=data;
temp1->next=NULL;
if(n==1)
{
    temp1->next=head;
    head=temp1;
    return;
}
struct Node* temp2=head;
int i;
for(i=0;i<n-2;i++)
    {
temp2=temp2->next;//to traverse to n-1th nnode to insert at nth node
}
temp1->next=temp2->next;
temp2->next=temp1;
}
void Print(){
struct Node* temp=head;
while(temp!=NULL){
    printf(" %d",temp->data);
    temp=temp->next;
    }
    printf("\n");
}


