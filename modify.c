#include "student.h"

void modify_student(void)
{
    struct student *temp;
    char choice, name[50];
    int roll, count = 0;
    int found = 0;
    float percentage;

    if (head == NULL)
    {
        printf("No student records available!\n");
        return;
    }

    printf("\nModify by:\n");
    printf("R. Roll Number\n");
    printf("N. Name\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);

    if (choice == 'R' || choice == 'r')
    {
        printf("Enter roll number: ");
        scanf("%d", &roll);
    }
    else if (choice == 'N' || choice == 'n')
    {
        printf("Enter student name: ");
        scanf(" %49[^\n]", name);

        temp = head;

        while (temp != NULL)
        {
            if (strcmp(temp->name, name) == 0)
            {
                printf("Roll No: %d  Name: %s\n",
                       temp->rollno, temp->name);
                count++;
            }

            temp = temp->next;
        }

        if (count == 0)
        {
            printf("Student not found!\n");
            return;
        }

        printf("Enter roll number to modify: ");
        scanf("%d", &roll);
    }
    else
    {
        printf("Invalid choice!\n");
        return;
    }

    temp = head;

    while (temp != NULL)
    {
        if (temp->rollno == roll)
        {
            if (choice == 'N' || choice == 'n')
            {
                if (strcmp(temp->name, name) != 0)
                {
                    printf("Name and roll number do not match!\n");
                    return;
                }
            }

            found = 1;
            break;
        }

        temp = temp->next;
    }

    if (found == 0)
    {
        printf("Student record not found!\n");
        return;
    }

    printf("\n1. Modify Name\n");
    printf("2. Modify Percentage\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter new name: ");
        scanf(" %49[^\n]", temp->name);
    }
    else if (choice == 2)
    {
        printf("Enter new percentage: ");
        scanf("%f", &percentage);

        if (percentage < 0 || percentage > 100)
        {
            printf("Invalid percentage!\n");
            return;
        }

        temp->percentage = percentage;
    }
    else
    {
        printf("Invalid choice!\n");
        return;
    }

    printf("Student record modified successfully!\n");
}
