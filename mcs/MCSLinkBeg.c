#include<stdlib.h>
#include<stdio.h>
struct Node{
int data;
struct Node* next;
};

struct Node* head;//Note head here is declared as global variable
void Printing();
void Insert(int);

int main(){
head=NULL;
printf("How many numbers you want to enter?");
int i,n,x;
scanf("%d",&n);
for(i=0;i<n;i++){
    printf("Enter the number you want to enter");
    scanf("%d",&x);
    Insert(x);
    Printing();
    }

}

void Insert(int x){
struct Node* temp =(struct Node*)malloc(sizeof(struct Node));
temp->data=x;
temp->next=head;
head=temp;


}

void Printing(){
    struct Node* temp = head;
    printf("List is:");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
    }

