#include<stdio.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main()
{
	int n = 8;
	int v[] = {0, 2, 4, 6, 8, 20, 46, 671};
	int x = 2;
	
	int ans, ans2;

	ans = binsearch(x, v, n);
	ans2 = binsearch2(x, v, n);

	printf("%d\n", ans);
	printf("%d\n", ans2);


}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n-1;
	while( low <= high ){
		mid = (low + high)/2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}

	return -1;
}

int binsearch2(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n-1;

	while( low <= high && x != v[mid = (low+high)/2] ){
		//mid = (low + high)/2; < この書き方だとWhile条件式内に入れなければならない
		if (x < v[mid])
			high = mid - 1;
		else 
			low = mid + 1;
	}

	return (x == v[mid]) ? mid : -1;
}

