#include "student.h"

struct student *head = NULL;

int main()
{
    char choice;

    load_student();

    while (1)
    {
        printf("\n===== STUDENT RECORD MANAGEMENT SYSTEM =====\n");
        printf("A. Add Student\n");
        printf("D. Delete Student\n");
        printf("S. Display Students\n");
        printf("M. Modify Student\n");
        printf("T. Sort Students\n");
        printf("R. Reverse Records\n");
        printf("L. Delete All Records\n");
        printf("V. Save Records\n");
        printf("E. Exit\n");

        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case 'A':
            case 'a':
                add_student();
                break;

            case 'D':
            case 'd':
                delete_student();
                break;

            case 'S':
            case 's':
                display_student();
                break;

            case 'M':
            case 'm':
                modify_student();
                break;

            case 'T':
            case 't':
                sort_student();
                break;

            case 'R':
            case 'r':
                reverse_student();
                break;

            case 'L':
            case 'l':
                delete_all();
                break;

            case 'V':
            case 'v':
                save_student();
                break;

            case 'E':
            case 'e':
            {
                char save_choice;

                printf("Save before exit? (Y/N): ");
                scanf(" %c", &save_choice);

                if (save_choice == 'Y' || save_choice == 'y')
                    save_student();

                delete_all();
                printf("Thank you!\n");
                return 0;
            }

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
