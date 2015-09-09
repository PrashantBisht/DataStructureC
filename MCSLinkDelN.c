
#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node* next;
};
struct Node* head;
void Insert(int,int);
void Delete(int);
void Print();

int main(){
    head=NULL;
    Insert(10,1);//2
    Insert(11,2);//2,3
    Insert(12,3);//423
    Insert(13,4);
    Print();
    int n;
    printf("ENter a position\n");
    scanf("%d",&n);
    Delete(n);
    Print();
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

void Delete(int n)
{
    struct Node* temp1=head;//temp1 points to 1st node
    if(n==1){
        head=temp1->next;//head points to second
        free(temp1);
        return;//or use else
    }
    int i;
    for(i=0;i<n-2;i++){
        temp1=temp1->next;//temp1 points to n-1th node
    }
    struct Node* temp2=temp1->next;//nth node
    temp1->next=temp2->next;//(n+1)th node
    free(temp2);//free temp2
}

void Print(){
struct Node* temp=head;
while(temp!=NULL){
    printf(" %d",temp->data);
    temp=temp->next;
    }
    printf("\n");
}
