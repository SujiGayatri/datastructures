#include<stdio.h>
struct student{
	char roll[100];
	char name[100];
	int age;
	float cgpa;
};
int main()
{
	struct student s1;
	struct student *s1_ptr;
	s1_ptr=&s1;
	scanf("%s",s1_ptr -> roll);
	scanf("%s",s1_ptr -> name);
	scanf("%d",&s1_ptr -> age);
	scanf("%f",&s1_ptr -> cgpa);
	printf("%s\t%s\t%d\t%.2f",s1_ptr->roll,s1_ptr->name,s1_ptr->age,s1_ptr->cgpa);
}
