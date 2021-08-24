#include<stdio.h>

#define	IN	1
#define	OUT	0

// 数字、空白文字、その他をカウント

int main()
{
	int c, i, nwhite, tmplength;
	int ndigit[20];
	int state;
	nwhite = tmplength = 0;

	for( i = 0; i < 20; i++) {
		ndigit[i] = 0;
	} // end of for

	state = IN;

	while( (c = getchar() ) != EOF) {
		if (c != ' ' && c != '\n' && c != '\t') 
			++tmplength;

		if (c == ' ' || c == '\n' || c == '\t') {
			++nwhite;
			state = OUT;
			if(tmplength > 0) 
				++ndigit[tmplength];
			tmplength = 0;
		} else if (state == OUT) {
			state = IN;
		}
	} // end of while

	printf("digits = ");
	for( i = 0; i < 20; i++)
		printf(" %d", ndigit[i]);

	printf(", white spade = %d.\n", nwhite);

	printf("----------Histgram---------\n");
	for( i = 0; i < 20; i++) {
		printf("%d\t|", i);
			for( int j = 0; j < ndigit[i]; j++) {
				printf("-");
			}
		printf("\n");
	}


} // end of main
