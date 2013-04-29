#include<stdio.h>
#include<conio.h>
struct rec
{
	char From;
	char To;
	long NorTime;
	long EarTime;
	long LstTime;
	long Float;
}task[30];
void input();
int count = 0;
char first, last, ans;
long max, min;
int main()
{
	int i, j, k;
	clrscr();
	input();
	clrscr();
	for (i=0; i<count; i++)
		if (task[i].From == first)
			task[i].EarTime = task[i].NorTime;

	for (i=0; i<count; i++)
	{
		max = 0;
		for (k=0; k<=i; k++)
			if (max<task[k].EarTime && task[i].To == task[k].To)
				max = task[k].EarTime;
		for (j=0; j<count; j++)
			if (task[i].To == task[j].From)
				task[j].EarTime = task[j].NorTime + max;

	}
	max = 0;
	for (i=0; i<count; i++)
		if (task[i].To == last)
			if (max < task[i].EarTime)
				max = task[i].EarTime;
	printf("\n\n\tThe length of the Critical Path = ");
	printf("%ld", max);
	for (i=0; i<count; i++)
		if (task[i].To == last)
		{
			task[i].LstTime = max;
			task[i].Float = task[i].LstTime - task[i].EarTime;
		}
	for (i = count-1; i>=0; i--)
	{
		min = 99999;
		for (k = count-1; k>i; k--)
			if (task[i].To == task[k].From && min > task[k].LstTime - task[k].NorTime)
			{
				min = task[k].LstTime - task[k].NorTime;
				task[i].LstTime = min;
				task[i].Float = min - task[i].EarTime;
			}
	}
	printf("\n\n\tThe Critical Path is : \n\n");
	printf("\t\t%c", first);
	for (i=0; i<count; i++)
		if (task[i].Float == 0)
			printf("-->%c", task[i].To);
	getch();
	return 0;
}

void input()
{
	long o, p, m;
	printf("\nEnter the following data for the given network : \n\n");
	do
	{
		fflush(stdin);
		printf("\n\tFrom : ");
		scanf("%c", &task[count].From);
		fflush(stdin);
		printf("\n\tTo : ");
		fflush(stdin);
		scanf("%c", &task[count].To);
		printf("\tEnter Optimistic, Most Liely and Pessimistic Time : ");
		scanf("%ld %ld %ld", &o, &m, &p);
		task[count].NorTime = (o + 4 * m + p)/6;

		printf("More ? Press<y> for Yes <n> for No.");
		fflush(stdin);
		scanf("%c", &ans);
		count++;
	}while(ans != 'n');
	printf("\nEnter the Initial Node : ");
	fflush(stdin);
	scanf("%c", &first);
	printf("\nEnter the Final Node : ");
	fflush(stdin);
	scanf("%c", &last);
}