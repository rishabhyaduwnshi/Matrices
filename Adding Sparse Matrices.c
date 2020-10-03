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

struct SparseMatrix* addMatrix(struct SparseMatrix *M1,struct SparseMatrix *M2)
{
	int i=0,j=0,k=0;
	struct SparseMatrix *M3;
	M3 = (struct SparseMatrix *)malloc(sizeof(struct SparseMatrix));
	M3->Array = (struct Element *)malloc((M1->nze+M2->nze)*sizeof(struct Element));
	
	
	while(i<M1->nze && j<M2->nze)
	{
	
	if(M1->Array[i].i < M2->Array[j].i)
	M3->Array[k++] = M1->Array[i++];
	
	else if(M1->Array[i].i > M2->Array[j].i)
	M3->Array[k++] = M2->Array[j++];
	
	else
	 {
	 	if(M1->Array[i].j < M2->Array[j].j)
	 	M3->Array[k++] = M1->Array[i++];
	 	
	 	else if(M1->Array[i].j > M1->Array[i].j)
	 	M3->Array[k++] = M2->Array[j++];
	 	
	 	else
	 	{
	 		M3->Array[k] = M1->Array[i];
	 		M3->Array[k++].x = M1->Array[i++].x + M2->Array[j++].x;
	 		
		 }
	 }
	 
	}
	 
	for(;i<M1->nze;i++)
		M3->Array[k++]	= M1->Array[i];
		
	for(;j<M2->nze;j++)
		M3->Array[k++] = M2->Array[j];
		
		
	M3->columns = M1->columns;
	M3->rows = M1->rows;
	M3->nze = k;
	
	return M3;
	
	
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
	struct SparseMatrix M1,M2,*M3;
	createMatrix(&M1);
	insertElements(&M1);
	
	createMatrix(&M2);
	insertElements(&M2);
	
	M3 = addMatrix(&M1,&M2);
	printf("\n");
	
	printf("Matrix 1 : \n");
	printMatrix(M1);
	
	printf("\n");
	
	printf("Matrix 2 : \n");
	printMatrix(M2);
	
	printf("\n");
	
	printf("Matrix 3 : \n");
	printMatrix(*M3);
	
	return 0;
	
}
