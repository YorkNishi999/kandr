#include<stdio.h>

int lower(int);

int main()
{
	int a = 'A';

	int b;
	
	b = lower(a);

	printf("%c\n", a);
	printf("%c\n", b);

}


int lower(int c)
{
//	if (c >= 'A' && c <= 'Z') 
//		return c + 'a' - 'A';
//	else 
//		return c;

	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c; 

	
}


