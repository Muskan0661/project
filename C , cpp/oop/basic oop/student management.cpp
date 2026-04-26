#include<stdio.h>
#include<string.h>
#define MAX_STUDENT 100
struct student {
	char name[50];
	int id;
	float marks[5];
	float avg;
	char grade;

};

void data(struct student *s )
{
	printf("enter name=");
	getchar();
	fgets(s->name,sizeof(s->name),stdin);
	s->name[strcspn(s->name, "\n")] = 0;

	printf("enter id=");
	scanf("%d",&s->id);

	printf("enter marks of =\n");
	for(int i=0; i<5; i++)
	{
		 printf("  Subject %d: ", i + 1);
		scanf("%f",&s->marks[i]);

	} }


	void calculate(struct student *s)
	{
	float sum=0;
		for(int i=0; i<5; i++)
	{
		sum += s->marks[i]; }

        s->avg=sum/5;
	printf("average is %f\n",s->avg);

 if (s->avg >= 90)
        s->grade = 'A';
    else if (s->avg >= 75)
        s->grade = 'B';
    else if (s->avg >= 50)
        s->grade = 'C';
    else
        s->grade = 'F';

}
void display(struct student *s)
{
	printf("summary\n");
	printf("name: %s\n",s->name);
	printf("id: %d\n",s->id);
for(int i=0; i<5; i++)
{
	printf("marks %d: %f\n",i+1,s->marks[i]);
}
	printf("avg: %f\n",s->avg);
    printf("grade: %c",s->grade);
}

int searchstudent(struct student student[], int count , int id)
{
	for(int i=0; i<count; i++)
	{
		if(student[i].id==id)
		return i;
	}
	return -1;
}
int main ()
{
	struct student students[MAX_STUDENT];
	int n,i,searchid;

	printf("enter num of students=");
	scanf("%d",&n);

	for(int i=0; i<n; i++)
	{
		printf("details of student %d\n",i+1);
		data(&students[i]);
		calculate(&students[i]);
	}

	printf("student report\n");
	for(int i=0; i<n; i++)
	{
		display(&students[i]);
	}
printf("search by id , enter student id=");
scanf("%d",&searchid);
int id=searchstudent(students, n, searchid);

if(id!=-1)
{
	printf("student found \n");
	display(&students[id]);
}
else
{
	printf("student with id %d not found \n",searchid);
}
}