//not working

#include<stdio.h>
#include<stdlib.h>

struct BST{
	int key;
	struct BST *left;
	struct BST *right; 
};

typedef struct BST node;
node *root = NULL;



node* insert(node *p ,int item){
	
	node *newNode = (node*)malloc(sizeof(node));
	newNode->key = item;
	newNode->left = newNode->right = NULL;
	
	if(p == NULL){
		p = newNode;
	}
	else if(item < p->key){
		p->left = insert(p->left,item);
	}
	else{
		p->right = insert(p->right,item);
	}
	return newNode;
}

void inorderTraversal(node* p) {
	
  if (p == NULL) {
  	return;
  }
  inorderTraversal(p->left);
  printf("%d ->", p->key);
  inorderTraversal(p->right);
  
}

int main(){
	int choice,data;
	printf(" 1. Insert\n 2. Inorder Traversal\n 3. Exit\n");
	
	do{
		printf("\n Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf(" Enter the data: ");
					scanf("%d",&data);
					insert(root,data);
					break;
					
			case 2: printf(" Datas: ");
					inorderTraversal(root);
					break;
			
			case 3: break;
		}
	}while(choice != 3);
}

