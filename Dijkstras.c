#include<stdio.h>
#include<conio.h>
struct Node
{
	int point, dis, next_point, label;
}node[50];
int n, temp, dis_mat[100][100], row, row1, min, last, path[100], first;
void input();
int main()
{
	int i, j, k;
	clrscr();
	input();
	for(i=0; i<n; i++)
	{
		if (node[i].point == temp)
			row = i;
	}

	for(j=0; j<n; j++)
	{
		node[j].dis = dis_mat[row][j];
		node[j].next_point = node[row].point;
	}
	node[row].label = 1;
	
	do
	{
		for(i=0; i<n; i++)
		{
			if(node[i].label != 1)
			{
				if (node[i].dis <= node[row1].dis + dis_mat[row][i])
					node[i].dis = node[i].dis;
			
				else
				{
					node[i].dis = node[row].dis + dis_mat[row][i];
					node[i].next_point = node[row1].point;
				}
			}
		}
		
		min = 999;
		
		for(i=0; i<n; i++)
		{
			if (min > node[i].dis && node[i].label != 1)
			{
				min = node[i].dis;
				row1 = i;
			}
		}
		
		node[row1].label = 1;
		temp = node[row1].point;

		for(j=0; j<n; j++)
		{
			if (node[j].point == temp)
				row = j;
		}


	}while(temp != last);

	printf("\nShortest distance = %d", node[row1].dis);

	i = 0;
	do
	{
		path[i] = last;
		for(j=0; j<n; j++)
		{
			if (node[j].point == last)
				row = j;
		}
		
		last = node[row].next_point;
		i++;

	}while(last != first);
	printf("\nFirst ");

	i--;

	for(j=i; j>=0; j--)
		printf("\n%d", path[j]);

	getch();
	return 0;
}
void input()
{
	int i, j;
	printf("\nEnter no. of nodes: ");
	scanf("%d", &n);
	printf("\nEnter Label of nodes: ");
	for(i=0; i<n; i++)
		scanf("%d", &node[i].point);

	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("\nDistance between nodes %d %d : ", i+1, j+1);
			scanf("%d", &dis_mat[i][j]);
		}
	}

	printf("\nFirst Node: ");
	scanf("%d", &first);
	temp = first;
	printf("\nLast Node: ");
	scanf("%d", &last);
}




