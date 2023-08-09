#include<stdio.h>
#include<stdlib.h>

struct BST{
	int key;
	struct BST *left;
	struct BST *right; 
};

typedef struct BST node;

node* createNewNode(int item){
	node *newNode = (node*)malloc(sizeof(node));
	newNode->key = item;
	newNode->left = newNode->right = NULL;
	return newNode;
}

node* insert(node *root ,int item){
	
	node *newNode = createNewNode(item);
	if(root == NULL){
		root = newNode;
	}
	else if(item < root->key){
		root->left = insert(root->left,item);
	}
	else{
		root->right = insert(root->right,item);
	}
	return newNode;
}

void inorderTraversal(node* root) {
	
  if (root == NULL) {
  	return;
  }
  inorderTraversal(root->left);
  printf("%d -> ", root->key);
  inorderTraversal(root->right);
  
}
void preorderTraversal(node* p) {
	
  if (p == NULL) {
  	return;
  }
  printf("%d -> ", p->key);
  preorderTraversal(p->left);
  preorderTraversal(p->right);
  
}
void postorderTraversal(node* p) {
	
  if (p == NULL) {
  	return;
  }
  postorderTraversal(p->left);
  postorderTraversal(p->right);
  printf("%d -> ", p->key);
}

int main(){
	int choice,data;
	printf("\n 1. Insert\n 2. Inorder Traversal\n 3. Preorder Traversal\n 4. Postorder Traversal\n 5. Exit\n");
	node *root = NULL;
	do{
		printf("\n Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf(" Enter the data: ");
					scanf("%d",&data);
					insert(root,data);
					
			case 2: printf(" Datas: ");
					inorderTraversal(root);
					break;
					
			case 3: printf(" Datas: ");
					preorderTraversal(root);
					break;
					
			case 4: printf(" Datas: ");
					postorderTraversal(root);
					break;
			
			case 5: break;
		}
	}while(choice != 5);
}

