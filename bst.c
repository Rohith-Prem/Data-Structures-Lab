//C program to demonstrate insert operation in binary search tree
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
  
struct node{
    int key;
    struct node *left, *right;
};
  
struct node *newNode(int item){
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
//************************************************************************************/


bool isBST(struct node* root){    		 //using inorder traversal
    static struct node *prev = NULL;
     
    // traverse the tree in inorder and keep track of prev node
    if (root){
        if (!isBST(root->left))
          return false;
 
        // Allows only distinct valued nodes 
        if (prev != NULL && root->key <= prev->key)
          return false;
 
        prev = root;
	return isBST(root->right);
    }
 
    return true;
}
//*************************************************************************************/

void insert(struct node* root, int key){
	struct node* new = newNode(key);
	struct node* temp = root;
 
    // Do level order traversal until we find
    // an empty place. 
	if (temp->left == NULL && temp->right == NULL)
		temp->left = new;
    while (temp->left != NULL && temp->right != NULL){
        if (temp->left = NULL) {
            temp->left = new;
            break;
        }else
            temp = temp->left;
 
        if (temp->right = NULL) {
            temp->right = newNode(key);
            break;
        }else
            temp = temp->right;
    }
}

/*********************main function****************/
void main(){
	int ch = 1,r,key;bool flag;
	struct node* root;
	printf("Enter root node");
	scanf("%d",&r);
	root = newNode(r);
		
	while(ch == 1){
		printf("Enter a node");
		scanf("%d",&key);
		insert(root,key);
		printf("Enter Again(1/0)");
		scanf("%d",&ch);
	}
	flag = isBST(root);
	if(flag == true)
		printf("Yea!!!\n);
	else
		printf("Nay :(");
   
}














