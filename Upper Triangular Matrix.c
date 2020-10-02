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

//Using Column Major Representation in Array

void setElements(struct Matrix *M,int i,int j,int x)
{
	if(i<=j)
	{
		M->Array[j*(j-1)/2 + i-1] = x;
	}
}

int getElements(struct Matrix M,int i,int j)
{
	if(i<=j)
	{
		return M.Array[j*(j-1)/2 + i-1];
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
		if(i<=j)
		{
			printf("%d " ,M.Array[j*(j-1)/2 + i-1]);
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
	struct Matrix UT;
	printf("Enter the size of Matrix : ");
	scanf("%d",&UT.size);
	createMatrix(&UT);
	printf("Enter the Matrix : \n");
	for(i=1;i<=UT.size;i++)
	for(j=1;j<=UT.size;j++)
	{
		scanf("%d",&element);
		setElements(&UT,i,j,element);
	}
	
	printf("The Matrix is : \n\n");
	printMatrix(UT);
	
	printf("%d ",getElements(UT,3,4));
	
	
	
}
