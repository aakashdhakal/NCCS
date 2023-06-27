#include <stdio.h>
#define MAX_SIZE 5

struct list
{
    int data[MAX_SIZE];
    int size;
};

typedef struct list listType;

void insert(listType *);
void printList(listType *);
void deleteElement(listType *);
void search(listType *);
void modify(listType *);

int main()
{
    listType list;
    list.size = 0;
    int choice;
    printf("\n1. Insert\n2. Delete\n3. Search\n4. Modify\n5. Print\n6. Exit\n");
    do
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(&list);
            break;
        case 2:
            deleteElement(&list);
            break;
        case 3:
            search(&list);
            break;
        case 4:
            modify(&list);
            break;
        case 5:
            printList(&list);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 6);
}

void insert(listType *list)
{
    if (list->size == MAX_SIZE - 1)
    {
        printf("List is full\n");
        return;
    }
    int data, pos;
    printf("Enter data: ");
    scanf("%d", &data);
    printf("Enter position [1 - %d]: ", MAX_SIZE);
    scanf("%d", &pos);
    if (pos > MAX_SIZE || pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    else if (pos > list->size)
    {
        list->data[list->size] = data;
        printf("%d is inserted at the last of the list\n", data);
    }
    else
    {
        for (int i = list->size - 1; i >= pos - 1; i--)
        {
            list->data[i + 1] = list->data[i];
        }
        list->data[pos - 1] = data;
        printf("%d is inserted in the position %d of the list\n", data, pos);
    }
    list->size++;
}
void deleteElement(listType *list)
{
    if (list->size == 0)
    {
        printf("List is empty\n");
        return;
    }
    int pos, value;
    printf("Enter position [1 - %d]: ", list->size);
    scanf("%d", &pos);
    if (pos > list->size || pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    else
    {
        value = list->data[pos - 1];
        for (int i = pos - 1; i < list->size; i++)
        {
            list->data[i] = list->data[i + 1];
        }
        list->size--;
    }
    printf("The value %d at position %d is deleted\n", value, pos);
}
void modify(listType *list)
{
    int value, pos;
    printf("Enter position [1 - %d]: ", list->size);
    scanf("%d", &pos);
    printf("Enter new value: ");
    scanf("%d", &value);
    if (pos > list->size || pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    else
    {
        list->data[pos - 1] = value;
    }
    printf("The value at position %d is modified to %d\n", pos, value);
}
void search(listType *list)
{
    int value;
    printf("Enter value to search: ");
    scanf("%d", &value);
    for (int i = 0; i <= list->size; i++)
    {
        if (list->data[i] == value)
        {
            printf("The value found at position %d\n", i + 1);
            return;
        }
    }
    printf("The value is not found\n");
}

void printList(listType *list)
{
    if (list->size == 0)
    {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    for (int i = 0; i < list->size; i++)
    {
        printf("%d\t ", list->data[i]);
    }
    printf("\n");
}
