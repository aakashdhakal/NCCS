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
int getMin(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->key;
}

node *deleteNode(node *root, int item)
{

    if (root == NULL)
    {
        return root;
    }
    else if (root->key < item)
    {
        root->right = deleteNode(root->right, item);
    }
    else if (root->key > item)
    {
        root->left = deleteNode(root->left, item);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            int rightMin = getMin(root->right);
            root->key = rightMin;
            root->right = deleteNode(root->right, rightMin);
        }
    }
    return root;
}

node *search(node *root, int key)
{
    if (root == NULL)
    {
        printf("The key : %d is not found", key);
        return NULL;
    }
    else if (key < root->key)
        return search(root->left, key);
    else if (key > root->key)
        return search(root->right, key);
    else
        return root;
}
int main()
{
    int choice, data;
    printf("\n 1. Insert\n 2. Inorder Traversal\n 3. Preorder Traversal\n 4. Postorder Traversal\n 5. Delete\n 6. Search \n 7. Exit");
    node *root = NULL, *ptr;
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
            printf("\n");
            break;

        case 3:
            printf(" Datas: ");
            preorderTraversal(root);
            printf("\n");
            break;

        case 4:
            printf(" Datas: ");
            postorderTraversal(root);
            printf("\n");
            break;

        case 5:
            printf(" Enter the data to be deleted: ");
            scanf("%d", &data);
            deleteNode(root, data);
            break;

        case 6:
            printf(" Enter the key to be searched: ");
            scanf("%d", &data);
            ptr = search(root, data);
            if (ptr != NULL)
            {
                printf(" The key is found in the tree\n");
            }
            break;
        }
    } while (choice != 7);
    return 0;
}
