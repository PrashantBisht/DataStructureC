#include<stdlib.h>
#include<stdio.h>
struct Node{
int data;
struct Node* next;
};
//typedef struct Node{
 //       int data;
 //       struct Node* next;
//}Node; we can replce struct node with just node in whole program
//struct Node* head;//Note head here is not declared as global variable so it will not be available tp other fnc there we need to pass
void Printing(struct Node* head);
struct Node* Insert(struct Node* head,int);//pass by value

int main(){
struct Node* head=NULL;
printf("How many numbers you want to enter?");
int i,n,x;
scanf("%d",&n);
for(i=0;i<n;i++){
    printf("Enter the number you want to enter");
    scanf("%d",&x);
    head=Insert(head,x);//return address of head
    Printing(head);
    }

}

struct Node* Insert(struct Node * head,int x){//Head needs to be modified therefore return pointer to head
struct Node* temp =(struct Node*)malloc(sizeof(struct Node));
temp->data=x;
temp->next=head;
head=temp;
return head;

}

void Printing(struct Node* head){
    while(head!=NULL){
        printf("%d",head->data);
        head=head->next;
    }
    printf("\n");
    }

