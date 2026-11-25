#include "student.h"

void display_student(void)
{
    struct student *temp;

    if (head == NULL)
    {
        printf("No student records available!\n");
        return;
    }

    printf("\n---------------------------------------------\n");
    printf("%-10s %-20s %-10s\n", "Roll No", "Name", "Percentage");
    printf("---------------------------------------------\n");

    temp = head;

    while (temp != NULL)
    {
        printf("%-10d %-20s %-10.2f\n",
               temp->rollno,
               temp->name,
               temp->percentage);

        temp = temp->next;
    }

    printf("---------------------------------------------\n");
}
