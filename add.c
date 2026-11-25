#include "student.h"

void add_student(void)
{
    struct student *newnode, *temp;
    int roll, used;

    newnode = (struct student *)malloc(sizeof(struct student));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter student name: ");
    scanf(" %49[^\n]", newnode->name);

    printf("Enter percentage: ");
    scanf("%f", &newnode->percentage);

    if (newnode->percentage < 0 || newnode->percentage > 100)
    {
        printf("Invalid percentage!\n");
        free(newnode);
        return;
    }

    roll = 1;

    while (1)
    {
        used = 0;
        temp = head;

        while (temp != NULL)
        {
            if (temp->rollno == roll)
            {
                used = 1;
                break;
            }
            temp = temp->next;
        }

        if (used == 0)
            break;

        roll++;
    }

    newnode->rollno = roll;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    printf("Student added successfully!\n");
    printf("Assigned Roll Number: %d\n", roll);
}
