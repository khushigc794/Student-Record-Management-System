#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
};

extern struct student *head;

/* Function declarations */

void add_student(void);
void delete_student(void);
void display_student(void);
void modify_student(void);

void sort_student(void);
void reverse_student(void);
void delete_all(void);

void save_student(void);
void load_student(void);

#endif
