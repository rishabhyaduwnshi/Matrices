#include<stdio.h>
#include<stdlib.h>

struct Element
{
	int i;
	int j;
	int x;
};

struct SparseMatrix
{
	int rows;
	int columns;
	int nze;
	struct Element *Array;
};

void createMatrix(struct SparseMatrix *M)
{
	printf("Enter no of Rows and Columns : ");
	scanf("%d%d",&M->rows,&M->columns);
	
	printf("Enter number of non-zero elements : ");
	scanf("%d",&M->nze);
	
	M->Array = (struct Element *)malloc(M->nze*sizeof(struct Element));
	
}

void insertElements(struct SparseMatrix *M)
{
	int i;
	for(i=0;i<M->nze;i++)
	{
		printf("Enter Row No : ");
		scanf("%d",&M->Array[i].i);
		
		printf("Enter Column No : ");
		scanf("%d",&M->Array[i].j);
		
		printf("Enter Element : ");
		scanf("%d",&M->Array[i].x);
		
		printf("\n");
	}
}


void printMatrix(struct SparseMatrix M)
{
	int i,j,k=0;
	for(i=0;i<M.rows;i++)
	{
		for(j=0;j<M.columns;j++)
		{
			if(i == M.Array[k].i && j == M.Array[k].j)
			printf("%d ",M.Array[k++].x);
			
			else
			printf("0 ");
		}
		printf("\n");
	}
}


int main()
{
	struct SparseMatrix M;
	createMatrix(&M);
	insertElements(&M);
	printf("\n");
	printMatrix(M);
	
}
