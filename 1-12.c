#include<stdio.h>

#define	IN	1 // 単語の中
#define	OUT	0 // 単語の外

/* 入力中の行、単語、文字のカウント */
int main() 
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;

	while(( c = getchar() ) != EOF) {
		++nc;
		putchar(c);
		if( c == '\n' )
			++nl;
		if( c == ' ' || c == '\n' || c == '\t' ) {
			state = OUT;
			printf("\n");
		}
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}

	printf("gyou: %d\t tango: %d\t moji: %d\n", nl, nw, nc);

}
