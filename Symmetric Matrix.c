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

void setElements(struct Matrix *M,int i,int j, int x)
{
	if(i>=j)
	{
		M->Array[i*(i-1)/2 + j-1] = x;
	}
}

int getElements(struct Matrix M,int i,int j)
{
	if(i>=j)
	{
		return M.Array[i*(i-1)/2 + j-1];
	}
	else
		return M.Array[j*(j-1)/2 + i-1];
	
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
			printf("%d " ,M.Array[i*(i-1)/2 + j-1]);
		}
		else
			printf("%d " ,M.Array[j*(j-1)/2 + i-1]);
	}
		printf("\n");
	}
}
int main()
{
	int i,j,element;
	struct Matrix ST;
	printf("Enter the size of Matrix : ");
	scanf("%d",&ST.size);
	createMatrix(&ST);
	printf("Enter the Matrix : \n");
	for(i=1;i<=ST.size;i++)
	for(j=1;j<=ST.size;j++)
	{
		scanf("%d",&element);
		setElements(&ST,i,j,element);
	}
	printf("\n");
	printf("The Symmetric Matrix is : \n\n");
	printMatrix(ST);
	
}
