#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int key;
    struct BST *left;
    struct BST *right;
};

typedef struct BST node;

node *createNewNode(int item)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->key = item;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node *insert(node *root, int item)
{
    if (root == NULL)
    {
        return createNewNode(item);
    }

    if (item < root->key)
    {
        root->left = insert(root->left, item);
    }
    else
    {
        root->right = insert(root->right, item);
    }
    return root;
}

void inorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%d -> ", root->key);
    inorderTraversal(root->right);
}
void preorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d -> ", root->key);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d -> ", root->key);
}

int main()
{
    int choice, data;
    printf("\n 1. Insert\n 2. Inorder Traversal\n 3. Preorder Traversal\n 4. Postorder Traversal\n 5. Exit\n");
    node *root = NULL;
    do
    {
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf(" Enter the data: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;

        case 2:
            printf(" Datas: ");
            inorderTraversal(root);
            break;

        case 3:
            printf(" Datas: ");
            preorderTraversal(root);
            break;

        case 4:
            printf(" Datas: ");
            postorderTraversal(root);
            break;

        case 5:
            break;
        }
    } while (choice != 5);
    return 0;
}
