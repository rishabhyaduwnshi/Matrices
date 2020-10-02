#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
	int *Array;
	int size;
};


void createMatrix(struct Matrix *M)
{
	int x;
	x = (M->size*(M->size+1))/2;
	M->Array = (int*)malloc(x*sizeof(int));
}

//Using Row Major Representation in Array

void setElements(struct Matrix *M,int i,int j,int x)
{
	if(i>=j)
	{
		M->Array[M->size*(j-1) + (j-2)*(j-1)/2 + i-j] = x;
	}
}

int getElements(struct Matrix M,int i,int j)
{
	if(i>=j)
	{
		return M.Array[M.size*(j-1) + (j-2)*(j-1)/2 + i-j];
	}
	else
		return 0;
	
}

void printMatrix(struct Matrix M)
{
	int i,j;
	for(i=1;i<=M.size;i++)
	{
	for(j=1;j<=M.size;j++)
	{
		if(i>=j)
		{
			printf("%d " ,M.Array[M.size*(j-1) + (j-2)*(j-1)/2 + i-j]);
		}
		else
			printf("0 ");
	}
		printf("\n");
	}
}
int main()
{
	int i,j,element;
	struct Matrix LT;
	printf("Enter the size of Matrix : ");
	scanf("%d",&LT.size);
	createMatrix(&LT);
	printf("Enter the Matrix : \n");
	for(i=1;i<=LT.size;i++)
	for(j=1;j<=LT.size;j++)
	{
		scanf("%d",&element);
		setElements(&LT,i,j,element);
	}
	
	printf("The Matrix is : \n\n");
	printMatrix(LT);
	
	
	printf("%d ",getElements(LT,3,3));
	
	
}
