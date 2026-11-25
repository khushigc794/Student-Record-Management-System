#include "student.h"

void sort_student(void)
{
    struct student *i, *j;
    int roll;
    char name[50];
    float percentage;
    int choice;

    if (head == NULL || head->next == NULL)
    {
        printf("Not enough records to sort!\n");
        return;
    }

    printf("\n1. Sort by Name\n");
    printf("2. Sort by Percentage (Descending)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2)
    {
        printf("Invalid choice!\n");
        return;
    }

    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if ((choice == 1 && strcmp(i->name, j->name) > 0) ||
                (choice == 2 && i->percentage < j->percentage))
            {
                roll = i->rollno;
                i->rollno = j->rollno;
                j->rollno = roll;

                strcpy(name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, name);

                percentage = i->percentage;
                i->percentage = j->percentage;
                j->percentage = percentage;
            }
        }
    }

    printf("Records sorted successfully!\n");
}

void reverse_student(void)
{
    struct student *prev = NULL;
    struct student *current = head;
    struct student *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    printf("Records reversed successfully!\n");
}

void delete_all(void)
{
    struct student *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("All student records deleted from memory!\n");
}
