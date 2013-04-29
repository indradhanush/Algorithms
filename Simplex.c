#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define M 9999
void inco();
void outgo();
void nexttable();
int i,j,col,row,tempcol,contype,t,in,out,flag1,obj = 1,basis[10];
float x[10] = {0},a[10][10] = {0},min,keyrow,key,cost[30] = {0};
void main()
{
	clrscr();
	printf("\nEnter the no of decision variables:");
	scanf("%d",&col);
	tempcol = col;
	printf("\nEnter the no of constraints:");
	scanf("%d",&row);
	printf("\nEnter the costs of the variables in objective function:\n");
	for(i=1;i<=col;i++)
	scanf("%f",&cost[i]);
	printf("\nEnter the co-efficient matrix:\n");
	for(i=0;i<row;i++)
		for(j=1;j<=col;j++)
			scanf("%f",&a[i][j]);
	printf("\n\t For `<=': Press 0.\n\t For `=': Press 1.\n\t For `>=': Press 2");
	for(i=0;i<row;i++)
	{
		printf("\nEnter type and right-hand side of %d constants:\n",i+1);
		scanf("%d %f",&contype,&a[i][0]);
		switch(contype)
		{
			case 0: basis[i] = ++col;
				a[i][col] = 1.0;
				break;
			case 1: basis[i] = ++col;
				cost[col] = -M;
				a[i][col] = 1.0;
				break;
			case 2: a[i][++col] = -1.0;
				a[i][++col] = 1.0;
				basis[i] = col;
				cost[col] = -M;
				break;
		}
	}
	for(j=0;j<=col;j++)
	{
		for(i=0;i<row;i++)
			a[row][j]+=cost[basis[i]]*a[i][j];
			a[row][j]-=cost[j];
	}
	while(flag1 == 0)
	{
		inco();
		if(flag1 == 1)
		break;
		outgo();
		nexttable();
		basis[out] = in;
	}
	for(i=0;i<row;i++)
		x[basis[i]] = a[i][0];
			for(j=1;j<=tempcol;j++)
				printf("\nX[%d] = %g",j,x[j]);
	printf("\nThe value of the objective function is %1.1f",a[row][0]);
	getch();
}
void inco()
{
	flag1 = 1;
	min = 0;
	for(j=1;j<=col;j++)
		if(min > a[row][j] && a[row][j] < 0)
		{
			min = a[row][j];
			in = j;
			flag1 = 0;
		}
}
void outgo()
{
	min = 9999;
	for(i=0;i<row;i++)
		if(min > a[i][0] / a[i][in] && a[i][in] > 0)
		{
			min = a[i][0] / a[i][in];
			out = i;
		}
}
void nexttable()
{
	key = a[out][in];
	for(i=0;i<=row;i++)
	{
		if(i != out)
		{
			keyrow = a[i][in];
			for(j=0;j<=col;j++)
				a[i][j] = a[i][j] - keyrow * a[out][j] / key;
		}
	}
	for(j=0;j<=col;j++)
		a[out][j] = a[out][j] / key;
}