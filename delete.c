#include "student.h"

void delete_student(void)
{
    struct student *temp, *prev;
    struct student *match;
    char choice, name[50];
    int roll, count = 0;

    if (head == NULL)
    {
        printf("No student records available!\n");
        return;
    }

    printf("\nDelete by:\n");
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

        if (count > 1)
            printf("Multiple records found. Select roll number.\n");

        printf("Enter roll number to delete: ");
        scanf("%d", &roll);
    }
    else
    {
        printf("Invalid choice!\n");
        return;
    }

    temp = head;
    prev = NULL;

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

            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Student deleted successfully!\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Student record not found!\n");
}
  
