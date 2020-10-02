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
	x = 3*M->size-2;
	M->Array = (int*)malloc(x*sizeof(int));
}

//Using Row Major Representation in Array

void setElements(struct Matrix *M,int i,int j,int x)
{
	if(i-j == 1)
	{
		M->Array[i-2] = x;
	}
	else if(i-j == 0)
	{
		M->Array[M->size-1 + i-1] = x;
	}
	else if(i-j == -1)
	{
		M->Array[2*M->size-1 + i-1] = x;
	}
}

int getElements(struct Matrix *M,int i,int j)
{
	if(i-j == 1)
	{
		return M->Array[i-2];
	}
	else if(i-j == 0)
	{
		return M->Array[M->size-1 + i-1];
	}
	else if(i-j == -1)
	{
		return	M->Array[2*M->size-1 + i-1];
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
	{
		if(i-j == 1)
	{
		printf("%d ",M.Array[i-2]);
	}
	else if(i-j == 0)
	{
		printf("%d ",M.Array[M.size-1 + i-1]);
	}
	else if(i-j == -1)
	{
		printf("%d ",M.Array[2*M.size-1 + i-1]);
	}
	else
	  	printf("0 ");
		
	}
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
	{
	for(j=1;j<=LT.size;j++)
	{
		scanf("%d",&element);
		setElements(&LT,i,j,element);
	}
	}
	printf("The Tridiagonal Matrix is : \n\n");
	printMatrix(LT);
	
	
	printf("%d ",getElements(&LT,3,3));
	
	
}
