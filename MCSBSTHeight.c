#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Definition of Node for Binary search tree
struct BstNode {
	int data;
	struct BstNode* left;
	struct BstNode* right;
};
struct BstNode* GetNewNode(int);
struct BstNode* Insert(struct BstNode*,int );
int findHeight(struct BstNode *);
int max(int ,int );
//struct BstNode* findMin(struct BstNode* root)
// Function to create a new Node in heap
struct BstNode* GetNewNode(int data) {
	struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node
struct BstNode* Insert(struct BstNode* root,int data) {//pass by value therefore * used and reurn stmt.otherwise pbarg ** no return
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree.
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree.
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}
int findHeight(struct BstNode * root){
    int LT,RT;
    if(root==NULL){
        return 0;
    }
    else{
        LT=findHeight(root->left);
        RT=findHeight(root->right);
    }
if (LT >RT )
           return(LT+1);
       else
        return(RT+1);
};


//BstNode* findMin(BstNode* root)
int main() {
    int a;
	struct BstNode* root = NULL;  // Creating an empty tree
	/*Code to test the logic*/
	root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	// Ask user to enter a number.
a=findHeight(root);
printf("%d",a);
}
