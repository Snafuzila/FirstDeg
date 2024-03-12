#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int* returnLucas(int n);
int* evenOdd(int* a, int* n, int isEven);
int* vecMultiplication(int* a, int* b);
void MulButPos(int* a, int n);
int* notInArr(int* a, int* n);

int* Q10(int* a, int n);

int main() 
{
	int arr[] = { 6, 3, 9, 10, 11, 5 };
	int* newarr = Q10(arr, 6);
	for (size_t i = 0; i < 6; i++)
	{
		printf("%d\n", newarr[i]);
	}
	free(newarr);
}
int* returnLucas(int n) 
{
	n++;
	int *a = (int*)malloc(n*sizeof(int));
	assert(a != NULL);
	a[0] = 2;
	if (n == 1) return a;
	a[1] = 1;
	if (n == 2) return a;
	int i;
	for (i = 2; i < n; i++)
	{
		a[i] = (a[i - 1] + a[i - 2]);
	}
	return a;
}
int* evenOdd(int* a, int* n, int isEven) 
{
	int* newarr = (int*)calloc(*n, sizeof(int));
	int newi = 0;
	if (isEven) 
	{
		for (size_t i = 0; i < *n; i++)
		{
			if (a[i] % 2 == 0) 
			{
				newarr[newi] = a[i];
				newi++;
			}
		}
	}
	else
		for (size_t i = 0; i < *n; i++)
		{
			if (a[i] % 2 == 1)
			{
				newarr[newi] = a[i];
				newi++;
			}
		}
	free(a);
	*n = newi;
	return newarr;
}
int* vecMultiplication(int* a, int* b) {
	int* mulVec = (int*)calloc(3, sizeof(int));
	assert(mulVec != NULL);
	mulVec[0] = (a[1] * b[2] - a[2] * b[1]);
	mulVec[1] = (a[2] * b[0] - a[0] * b[2]);
	mulVec[2] = (a[0] * b[1] - a[1] * b[0]);
	return mulVec;
}
void MulButPos(int* a, int n) {
	int* newarr = (int*)calloc(n, sizeof(int));

	assert(newarr != NULL);
	int sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		newarr[i] = a[i];
		a[i] = 0;
	}
	for (size_t i = 0; i < n; i++)
	{
		sum = 1;
		for (size_t m = 0; m < n; m++)
		{
			if (m != i)
				sum *= newarr[m];

		}
		a[i] = sum;
	}
	free(newarr);
}
int* notInArr(int* a, int* n)
{
	*n++;
	int* monim = (int*)calloc(*n, sizeof(int));
	int newn = 0;
	int* newarr = (int*)calloc(newn, sizeof(int));
	for (size_t i = 0; i < *n; i++)
	{
		monim[a[i]] = 1;
	}
	for (size_t i = 0; i < *n; i++)
	{
		if (monim[i] == 0)
		{
			newn++;
			newarr = (int*)realloc(newarr, newn);
			newarr[newn] = i;
			
		}
	}
	free(monim);
	*n = newn;
	return newarr;
}
int* Q10(int* a, int n)
{
	int* newArr = (int*)calloc(n, sizeof(int));
	assert(newArr != NULL);
	for (size_t i = 0; i < n-1; i++)
	{
		for (size_t j = i; j < n-1; j++)
		{
			if (a[j + 1] > a[i])
			{
				newArr[i] = a[j + 1];
				break;
			}
		}
		if (newArr[i] == 0) 
		{
			newArr[i] = -1;
		}
	}
	newArr[n - 1] = -1;
	return newArr;
}
