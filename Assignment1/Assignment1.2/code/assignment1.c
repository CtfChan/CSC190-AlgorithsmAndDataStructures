#include "assignment1.h"

double ** choleskyDecomp(double ** A, int n, int i)
{

	int check;
	check = identity(A, n);
	if (check == 1) {

	  freeMatrix(A, n);
	  return A;
	}
	

	if (i+1 == n) {
		double **matL;
		initMatrix(&matL, n);
		double repeat;
		repeat = sqrt(A[i][i]);
			
		// turn the whole thing into an identity matrix
		int u, j;
		for (u = 0; u < n; u++) {
			for (j = 0; j < n; j++) {
				if (u==j){
					matL[u][j] = 1;
				}
			}
		}
			


		matL[i][i] = repeat;

		double **newA;
		initMatrix(&newA, n);

		// make the whole thing an identity matrix
		for (u = 0; u < n; u++) {
			for (j = 0; j < n; j++) {
				if (u==j){
					newA[u][j] = 1;
				}
			}
		}
		
		freeMatrix(matL, n);
		freeMatrix(newA, n);
		return mult(matL, choleskyDecomp(newA, n, i+1), n);
	}
	
	
	//compute L 
	double **matL;
	initMatrix(&matL, n);
	double repeat;
	repeat = sqrt(A[i][i]);
	
	

	// turn the whole thing into an identity matrix
	int u, j;
	for (u = 0; u < n; u++) {
		for (j = 0; j < n; j++) {
			if (u==j){
				matL[u][j] = 1;
			}
		}
	}
	
	for (u = i+1; u < n; u++) {
		matL[u][i] = A[u][i] / repeat;
	}

	//determine A@i
	double **newA;
	initMatrix(&newA, n);

	// make the whole thing an identity matrix
	for (u = 0; u < n; u++) {
		for (j = 0; j < n; j++) {
			if (u==j){
				newA[u][j] = 1;
			}
		}
	}



	matL[i][i] = repeat;



	for (u = i + 1; u < n; u++) {
		for(j = i + 1; j < n; j++) {
			newA[u][j]= A[u][j]-((A[u][i] * A[j][i])/ A[i][i]);
		}
	}
	

	freeMatrix(matL,n);
	freeMatrix(newA,n);
	freeMatrix(A,n);
	return mult(matL, choleskyDecomp(newA, n, i+1), n);

     


}

double ** mult(double ** L1,double ** L2, int n)
{
	double **mat2;
	initMatrix(&mat2, n);
	int i, j;
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++) 
		{
			int k;
			for (k = 0; k < n; k ++) {
				mat2[i][j] += (L1[i][k]) * (L2[k][j]);
				// mat2[i][j] += (L1[k][j]) * (L2[i][k]);

			}
		}
	}	

	if (L1 == L2) {
		freeMatrix(L1, n);
	}
	else {
		freeMatrix(L1, n);
		freeMatrix(L2, n);
	}

	return mat2;
	

}

int identity(double ** A, int n)
{
	int i, j;
	for (i = 0; i < n; i++) 
		{
			for (j = 0; j < n; j++) 
			{
				if (i == j) {
					if (A[i][j] != 1) {
						return 0;
					}
					continue;
				}
				else if (A[i][j] != 0) {
					return 0;
				}
			}
		}	

	return 1;




}


void initMatrix(double ***mat,int n)
{
	double **a = (double**)malloc(n*sizeof(double*));
	int i, j;
	for (i = 0; i < n; i++) {
		a[i] = (double*)malloc(n*sizeof(double));
		for (j = 0; j < n; j++) {
			a[i][j] = 0;
		}
	}
	*mat = a;
}

double **readMatrix(char * filename)
{
	FILE *fp = fopen(filename, "r");
	int i, j;
	double **mat1;
	initMatrix(&mat1, MATSIZE);	
	for (i = 0; i < MATSIZE; i++) 
	{
		for (j = 0; j < MATSIZE; j++) 
		{
			fscanf(fp, "%lf", &(mat1[i][j]));
		}
	}	
	fclose(fp);
	return mat1;
}

void freeMatrix(double ** matrix, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		free(matrix[i]);
				
	}
	free(matrix);
}

void printMatrix(double ** A, int n) 
{
int i, j;
for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j ++)
		{
			printf("%lf ", A[i][j]); //lf is long float, f is float, d is int
			
		}
		printf("\n"); 
	}
}
#include "assignment1.h"

double ** choleskyDecomp(double ** A, int n, int i)
{

	int check;
	check = identity(A, n);
	if (check == 1) {
		return A;
	}
	

	if (i+1 == n) {
		double **matL;
		initMatrix(&matL, n);
		double repeat;
		repeat = sqrt(A[i][i]);
			
		// turn the whole thing into an identity matrix
		int u, j;
		for (u = 0; u < n; u++) {
			for (j = 0; j < n; j++) {
				if (u==j){
					matL[u][j] = 1;
				}
			}
		}
			


		matL[i][i] = repeat;

		double **newA;
		initMatrix(&newA, n);

		// make the whole thing an identity matrix
		for (u = 0; u < n; u++) {
			for (j = 0; j < n; j++) {
				if (u==j){
					newA[u][j] = 1;
				}
			}
		}

	return mult(matL, choleskyDecomp(newA, n, i+1), n);
 


	}
	
	
	//compute L 
	double **matL;
	initMatrix(&matL, n);
	double repeat;
	repeat = sqrt(A[i][i]);
	
	

	// turn the whole thing into an identity matrix
	int u, j;
	for (u = 0; u < n; u++) {
		for (j = 0; j < n; j++) {
			if (u==j){
				matL[u][j] = 1;
			}
		}
	}
	
	for (u = i+1; u < n; u++) {
		matL[u][i] = A[u][i] / repeat;
	}

	//determine A@i
	double **newA;
	initMatrix(&newA, n);

	// make the whole thing an identity matrix
	for (u = 0; u < n; u++) {
		for (j = 0; j < n; j++) {
			if (u==j){
				newA[u][j] = 1;
			}
		}
	}



	matL[i][i] = repeat;



	for (u = i + 1; u < n; u++) {
		for(j = i + 1; j < n; j++) {
			newA[u][j]= A[u][j]-((A[u][i] * A[j][i])/ A[i][i]);
		}
	}
	



	/*
	printMatrix(newA, n);
	printf("above is newA, %d\n", i);
	
	printMatrix(matL, n); 
	printf("above is matL, %d \n", i);	
	*/



	return mult(matL, choleskyDecomp(newA, n, i+1), n);

}

double ** mult(double ** L1,double ** L2, int n)
{
	double **mat2;
	initMatrix(&mat2, n);
	int i, j;
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++) 
		{
			int k;
			for (k = 0; k < n; k ++) {
				mat2[i][j] += (L1[i][k]) * (L2[k][j]);
				// mat2[i][j] += (L1[k][j]) * (L2[i][k]);

			}
		}
	}	

	if (L1 == L2) {
		freeMatrix(L1, n);
	}
	else {
		freeMatrix(L1, n);
		freeMatrix(L2, n);
	}

	return mat2;
	

}

int identity(double ** A, int n)
{
	int i, j;
	for (i = 0; i < n; i++) 
		{
			for (j = 0; j < n; j++) 
			{
				if (i == j) {
					if (A[i][j] != 1) {
						return 0;
					}
					continue;
				}
				else if (A[i][j] != 0) {
					return 0;
				}
			}
		}	

	return 1;




}


void initMatrix(double ***mat,int n)
{
	double **a = (double**)malloc(n*sizeof(double*));
	int i, j;
	for (i = 0; i < n; i++) {
		a[i] = (double*)malloc(n*sizeof(double));
		for (j = 0; j < n; j++) {
			a[i][j] = 0;
		}
	}
	*mat = a;
}

double **readMatrix(char * filename)
{
	FILE *fp = fopen(filename, "r");
	int i, j;
	double **mat1;
	initMatrix(&mat1, MATSIZE);	
	for (i = 0; i < MATSIZE; i++) 
	{
		for (j = 0; j < MATSIZE; j++) 
		{
			fscanf(fp, "%lf", &(mat1[i][j]));
		}
	}	
	fclose(fp);
	return mat1;
}

void freeMatrix(double ** matrix, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		free(matrix[i]);
				
	}
	free(matrix);
}

void printMatrix(double ** A, int n) 
{
int i, j;
for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j ++)
		{
			printf("%lf ", A[i][j]); //lf is long float, f is float, d is int
			
		}
		printf("\n"); 
	}
}
