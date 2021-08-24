#include<stdio.h>

// 数字、空白文字、その他をカウント

int main()
{
	int c, i, nwhite, nother;
	int ndigit[10];
	nwhite = nother = 0;

	for( i = 0; i < 10; i++) {
		ndigit[i] = 0;
	} // end of for

	while( (c = getchar() ) != EOF) {
		if (c >= '0' && c <= '9') {
			++ndigit[c-'0'];
		} else if (c == ' ' || c == '\n' || c == '\t') {
			++nwhite;
		} else {
			++nother;
		}
	} // end of while

	printf("digits = ");
	for( i = 0; i < 10; i++)
		printf(" %d", ndigit[i]);

	printf(", white spade = %d, other = %d.\n", nwhite, nother);

} // end of main
