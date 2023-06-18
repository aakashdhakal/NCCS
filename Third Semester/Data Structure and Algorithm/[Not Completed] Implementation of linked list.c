#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node Node;
Node *start = NULL;
void insert(Node *);

int main()
{

    insert(&start);
    return 0;
}

void insert(Node *newnode)
{
    newnode = (Node *)malloc(sizeof(Node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (start == NULL)
    {
        newnode->next = NULL;
        start = newnode;
    }
    int option;
    printf("\n 1. Insert at the beginning\n 2. Insert at the end\n 3. Insert at a given position\n");
    printf("Enter your option: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        newnode->next = start;
        start = newnode;
        break;
    case 2:
        Node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        break;
    case 3:
        int pos;
        printf("Enter the position: ");
        scanf("%d", &pos);
        Node *temp = start;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        break;
    default:
        printf("Invalid option\n");
        break;
    }
