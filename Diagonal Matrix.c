#include<stdio.h>
#include<stdlib.h>

struct DiagonalMatrix
{
	int *Array;
	int size;
};

void createMatrix(struct DiagonalMatrix *M1)
{
	M1->Array = (int *)malloc(M1->size*sizeof(int));
}

void insertElements(struct DiagonalMatrix *M1)
{
	int i;
	for(i=0;i<M1->size;i++)
	scanf("%d",&(M1->Array[i]));	
}

int getElement(struct DiagonalMatrix M1)
{
	int row,column;
	printf("Enter the Row Number : ");
	scanf("%d",&row);
	
	printf("Enter the Column Number : ");
	scanf("%d",&column);
	
	if(row == column)
	return M1.Array[row-1];
	else 
	return 0;
}

void printMatrix(struct DiagonalMatrix M1)
{
	int i,j;
	for(i=1;i<=M1.size;i++)
	{
		for(j=1;j<=M1.size;j++)
		{
			if(i == j)
			printf("%d ",M1.Array[i-1]);
			else
			printf("0 ");
		}
		printf("\n");
	}
}


int main()
{
	struct DiagonalMatrix M1;
	printf("Enter the size of Matrix : ");
	scanf("%d",&M1.size);
	createMatrix(&M1);
	
	printf("Enter the diagonal elements : ");
	insertElements(&M1);
	printf("The matrix is : \n");
	printf("\n");
	printMatrix(M1);
	
	printf("\n");
	
	printf("The element present at this index is %d ",getElement(M1));
}
