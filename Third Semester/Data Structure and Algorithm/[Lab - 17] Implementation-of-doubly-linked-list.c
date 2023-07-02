// Code is not fully completed so please check once

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node Node;
Node *start = NULL;

void insert(int);
void delete(int);
void display();
void search();

int main()
{
    int option;
    printf("\n 1. Insert at the beginning\n 2. Insert at the end\n 3. Insert at a given position\n 4. Delete from the beginning\n 5. Delete from the end\n 6. Delete from a given position\n 7. Display\n 8. Search\n 9. Exit\n");

    do
    {
        printf("\nEnter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert(1);
            break;
        case 2:
            insert(2);
            break;
        case 3:
            insert(3);
            break;
        case 4:
            delete (1);
            break;
        case 5:
            delete (2);
            break;
        case 6:
            delete (3);
            break;
        case 7:
            display();
            break;
        case 8:
            search();
            break;
        case 9:
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    } while (option != 9);
    return 0;
}

void insert(int n)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    Node *temp;
    int pos, i;
    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    if (start == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        start = newnode;
    }
    else if (n == 1)
    {
        newnode->next = start;
        start->prev = newnode;
        start = newnode;
    }
    else if (n == 2)
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newnode->prev = temp;
        temp->next = newnode;
        newnode->next = NULL;
    }
    else
    {
        printf("Enter the position: ");
        scanf("%d", &pos);
        temp = start;
        i = 1;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        temp->next->prev = newnode;
    }
    printf("The data is inserted successfully\n");
}

void display()
{
    Node *temp;
    temp = start;
    if (temp == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete(int n)
{
    if (start == NULL)
    {
        printf("The list is empty\n");
        return;
    }

    Node *temp = start;

    if (n == 1)
    {
        start = start->next;
        if (start != NULL)
        {
            start->prev = NULL;
        }
        free(temp);
    }
    else if (n == 2)
    {
        if (start->next == NULL)
        {
            free(start);
            start = NULL;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->prev->next = NULL;
            free(temp);
        }
    }
    else
    {
        int pos;
        printf("Enter the position: ");
        scanf("%d", &pos);

        int i = 1;
        while (temp != NULL && i < pos)
        {
            temp = temp->next;
            i++;
        }

        if (temp == NULL)
        {
            printf("Invalid Position\n");
            return;
        }

        if (temp->prev != NULL)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            start = temp->next;
        }

        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }

        free(temp);
    }

    printf("Node deleted successfully\n");
}

void search()
{
    if (start == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    int data;
    printf("Enter the data to be searched: ");
    scanf("%d", &data);
    Node *temp = start;
    int position = 1;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("The data is found at position %d\n", position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("The data is not found\n");
}
