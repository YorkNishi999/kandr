#include <stdio.h>
#include <string.h>
#define MAX 1000000
void itob(int n, char s[], int b); 
void reverse(char s[]);


int main ()
{
	int n = 20000;
	char s[MAX];
	int b = 16;

	printf("10進数の整数: %d\n", n);
	printf("16進数だと %x\n", n);

	itob(n, s, b);

	reverse(s);
	printf("Strだと %s\n", s);

}

void itob(int n, char s[], int b) 
{
	int i = 0;
	
	do {
		s[i++] = (n % b > 9) ? (n % b + 39 + '0') : (n % b + '0');
	} while ((n /= b) > 0);

	s[i] = '\0';

}

void reverse(char s[])
{
	int i, j;
	char tmp;


	//for (i = 0, j = strlen(s)-1; s[i] != '\0'; ++i, --j) {＞これだと全部入れ替えて同じになっちゃう
	for (i = 0, j = strlen(s)-1; i < j; ++i, --j) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}

}

