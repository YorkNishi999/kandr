#include<stdio.h>
#define	swap(t, x, y)	{t = x; x = y; y = t;}

int main() {
	int x, y;
	int tmp;

	x = 10;
	y = 50;

	printf("%d\n", x);
	swap(tmp, x, y);
	printf("%d\n", x);

	return 0;

}
