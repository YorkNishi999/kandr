#include<stdio.h>

void swap( int *, int *);

int main() {
int a, b;

	a = 10;
	b = 24;

	printf("a b: %d %d\n",a, b);

	swap(&a, &b);

	printf("a b: %d %d\n",a, b);


}

void swap (int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
	
}