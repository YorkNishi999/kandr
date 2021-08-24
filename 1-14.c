#include<stdio.h>

#define	IN	1
#define	OUT	0
#define MAX	52

// 数字、空白文字、その他をカウント

int main()
{
	int c, i, nwhite;
	int tmpkind;
	int ndigit[MAX];
	int nalpha[MAX]; // count alphabet
	int state;
	nwhite = 0;
	tmpkind = 0;

	for( i = 0; i < MAX; i++) {
		ndigit[i] = 0;
	} // end of for
	for( i = 0; i < MAX; i++) {
		nalpha[i] = 0;
	} // end of for

	state = OUT;

	while( (c = getchar() ) != EOF) {
		if (c != ' ' && c != '\n' && c != '\t')
			++nalpha[c - 'A'];

		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			for(i = 0; i < MAX; i++) {
				if(nalpha[i] > 0) ++tmpkind;
			}

			++ndigit[tmpkind];
			tmpkind = 0;
			for( i = 0; i < MAX; i++) {
				nalpha[i] = 0;
			} 

		} else if (state == OUT) {
			state = IN;
		}
	} // end of while

	printf("----------Histgram---------\n");
	for( i = 0; i < MAX; i++) {
		printf("%d\t|", i);
			for( int j = 0; j < ndigit[i]; j++) {
				printf("-");
			}
		printf("\n");
	}


} // end of main
