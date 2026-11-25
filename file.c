#include "student.h"

void save_student(void)
{
    struct student *temp;
    FILE *fp;

    fp = fopen("student.dat", "wb");

    if (fp == NULL)
    {
        printf("Unable to open file!\n");
        return;
    }

    temp = head;

    while (temp != NULL)
    {
        fwrite(temp, sizeof(struct student), 1, fp);
        temp = temp->next;
    }

    fclose(fp);

    printf("Student records saved successfully!\n");
}

void load_student(void)
{
    struct student data;
    struct student *newnode, *temp;
    FILE *fp;

    fp = fopen("student.dat", "rb");

    if (fp == NULL)
        return;

    while (fread(&data, sizeof(struct student), 1, fp) == 1)
    {
        newnode = (struct student *)malloc(sizeof(struct student));

        if (newnode == NULL)
        {
            printf("Memory allocation failed!\n");
            fclose(fp);
            return;
        }

        newnode->rollno = data.rollno;
        strcpy(newnode->name, data.name);
        newnode->percentage = data.percentage;
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
    }

    fclose(fp);

    printf("Student records loaded successfully!\n");
}
