#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[20];
    int roll;
    float marks;
};
typedef struct student Student;

int main()
{
    Student *ptr;
    int n, i;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    ptr = (Student *)malloc(n * sizeof(Student));

    for (i = 0; i < n; i++)
    {
        printf("\nEnter the name of student: ");
        scanf("%s", (ptr + i)->name);
        printf("Enter the roll number of student: ");
        scanf("%d", &(ptr + i)->roll);
        printf("Enter the marks of student in DSA: ");
        scanf("%f", &(ptr + i)->marks);
    }

    printf("\nStudents that got less than 30 in DSA:\n");
    for (i = 0; i < n; i++)
    {
        if ((ptr + i)->marks < 30)
        {

            printf("\nName: %s\n", (ptr + i)->name);
            printf("Roll: %d\n", (ptr + i)->roll);
            printf("Marks: %.2f\n", (ptr + i)->marks);
        }
    }
    return 0;
}
