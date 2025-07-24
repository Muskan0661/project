#include <stdio.h>
void displayResults(float marks[], char *subjects[], float gpa)
{
    printf("\n--- Subject Marks ---\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%s: %.2f\n", subjects[i], marks[i]);
    }
    printf("\n---------------------\n");
    printf("Your SGPA is: %.2f\n", gpa / 16);
    printf("Thanks for using my program!!\n");
}
int main()
{
    float marks[8];
    char *subjects[] = {"Programming Fundamentals", "Applied Physics", "Calculas", "Functional English", "Islamiat Or Ethics", "FE Lab", "PF Lab", "ICT Lab"};
    for (int i = 0; i < 8; i++)
    {
        printf("Enter GPA obtained in %s: ", subjects[i]);
        scanf("%f", &marks[i]);
    }
    float gpa = (marks[0] * 3) + (marks[1] * 3) + (marks[2] * 3) + (marks[3] * 2) +
                (marks[4] * 2) + (marks[5] * 1) + (marks[6] * 1) + (marks[7] * 1);
    displayResults(marks, subjects, gpa);
    return 0;
}