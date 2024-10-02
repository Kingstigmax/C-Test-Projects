#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student
{
    int id;
    char name[50];
    int age;
    float grade;
};

int numStudents = 0;
struct Student students[MAX_STUDENTS]

void addStudent()
{
    if (numStudents >= MAX_STUDENTS) 
    {
        printf("Student limit reached!\n");
    } 

    struct Student s;
    printf("Enter ID: \n");
    scanf("%d", &s.id);
    printf(" Name: \n");
    scanf("%[^\n]]", s.name);
    printf(" Age: \n");
    scanf("%d", &s.age);
    printf(" Grade: \n");
    scanf("%f", &s.grade);

    students[numStudents++] = s; //Not working here.
    printf("Student added...\n");      
}


void displayStudents() 
{
    printf("Student Records: \n");
    for (int i = 0; i < numStudents; i++) 
    {
        printf("ID: %d, Name: %s, Age: %d, Grade: %.2f\n", students[i].id, students[i].name, students[i].age, students[i].grade);
    }

}


int main() 
{
    int choice;
    
    do 
    {
        printf("\nStudent Records System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}