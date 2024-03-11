#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
 
int Q1(int* arr, int n);//return value missing in array O(n)
int Q2(int* arr, int n);//return value missin in  sorted array O(logn)
int Q3(int* arr, int k, int key); //get array of doubles in increasing order {2,1,6,4,7,9,17,12} and key sum of doubles. if it exists return the place. O(logk)
int Q4(int* arr, int n, int k); //in bin searhc, reaturn the closes value to k. O(logn)
int Q5(int* arr, int n);
int Q7n(int* arr, int n); //find how many ones in{1,1,1,0,0,0,0,0} array O(logn) n size of array
int Q7t(int* arr, int n); //find how many ones in{1,1,1,0,0,0,0,0} array O(logt) t=length of 1
int Q8(int* arr, int n, int d); // increasing array, return the index between arrays in which d variable is the sub of i-(i-1). O(logn) 



void main()
{
	int arr[] = {2,4,7,12,20,31,46};
	printf("%d", Q8(arr,7,8));
		
}

int Q1(int* arr, int n)
{
	int i, sum = 0;
	for (i = 1; i <= n; i++)
		sum += i;
	// sum = ((1 + n) * n)/2;
	for (i = 0; i < n; i++)
		sum -= arr[i];
	return sum;
}
int Q2(int* arr, int n) // 0,1,2,4,5
{
	int low, mid, high;
	low = 0;
	high = n - 1;
	mid = (n - low) / 2 + low;
	while (low <= high) {
		
		if (arr[mid] == mid) {
			low = mid+1;
		}
		else
			high = mid-1;
		mid = (high - low) / 2 + low;
	}

	return low;
}
int Q3( int* arr, int k, int key)
{
	int first, mid, last;
	first = 0;
	last = (k-1);
	while(first<=last)
	{
		mid = first + (last - first)/ 2;
		printf("%d %d %d\n", first, mid, last);

		if ((arr[mid*2] + arr[mid*2 + 1]) == key)
		{
			return mid;
		}
		else if (arr[mid*2] + arr[mid*2 + 1] < key)
		{
			first = mid + 1;
		}
		else
			last = mid - 1;
	}
	return -1;
}
int Q4(int* arr, int n, int k)
{
	if (k > arr[n - 1]) return arr[n-1];
	if (k < arr[0]) return arr[0];

	int mid;
	int low = 0;
	int high = n - 2;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] < k)
			if	(arr[mid+1]>k)
			{
				if ((arr[mid + 1] - k) > (k - arr[mid])) return arr[mid];
				return arr[mid + 1];
			}
			else
				low = mid + 1; 
		else
			high = mid - 1;
	}
	return low;

}
int Q5(int* arr, int n)
{
	int low, mid, high;
	low = 0;
	high = n - 1;
	while (low < high) {
		mid = (high - low) / 2 + low;
		if (arr[mid] < arr[high])
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}
int Q7n(int*arr, int n)
{
	if (arr[n - 1] == 1) return n;
	if (arr[0] == 0) return 0;
	int low, mid, high;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] == 1)
		{
			if (arr[mid + 1] == 0) 
				return mid+1;
			else 
				low = mid + 1;
		}
		else high = mid - 1;
	}
}
int Q7t(int* arr, int n)
{
	int t = 1;
	if (arr[n - 1] == 1) return n;
	if (arr[0] == 0) return 0;
	while (arr[t]) 
	{
		n *= 2;
		if (t >= n)
		{
			t = n - 1;
		}
	}
	//return numOfOneslogn(arr, t);
	return t / 2 + Q7n(arr + t / 2, t - t / 2 + 1);
}
int Q8(int* arr, int n, int d)
{
	int low, mid, high;
	low = 0;
	high = n - 2;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid + 1] - arr[mid] == d) return mid;
		if (arr[mid + 1] - arr[mid] < d)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}