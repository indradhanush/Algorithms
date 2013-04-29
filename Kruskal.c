#include<stdio.h>
#include<conio.h>
typedef struct
{
	int node1;
	int node2;
	int wt;
}edge;

void sortedges(edge a[],int n)
{
	int i,j;
	edge temp;
 	
	for(i=0;i< n-1;i++)
  	    for(j=i+1;j< n;j++)
    		if(a[i].wt>a[j].wt)
    	    {
            	temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
}

int checkcycle(int p[],int i,int j)
{
	int v1,v2;
	v1 = i;
	v2 = j;
	
	while(p[i]>-1)
		i = p[i];

	while(p[j]>-1)
		j = p[j];
	
	if(i!=j)
	{
		p[j]=i;
		printf("%d %d\n",v1,v2);
		return 1;
	}
	return 0;
}

int main()
{
	edge e[100];
	int parent[100];
	int n,i,j,m,k = 1,cost = 0;
	printf("Enter number of nodes\n");
	scanf("%d",&n);

	for(i=0;i< n;i++)
		parent[i]=-1;

	i = 0;
	printf("Enter number of edges\n");
	scanf("%d",&m);

	for(i=0;i< m;i++)
	{
		printf("enter an edge and wt\n");
		scanf("%d %d %d", &e[i].node1,&e[i].node2,&e[i].wt);
	}

	sortedges(e,m);
	printf("\n\nEdges of the tree\n");
	i = 0;

	while(k< n)
	{
		if(checkcycle(parent,e[i].node1,e[i].node2))
		{
			k++;
			cost=cost+e[i].wt;
			i++;
		}
	}

	printf("COST = %d",cost);
	getch();
}
