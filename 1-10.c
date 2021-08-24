#include<stdio.h>

int main() 
{

	int c, ns, prev_c;
	
	ns = 0;

	while( (c = getchar() ) != EOF) {
		if( c == '\t' ){
			printf("\\t");
		}
		if( c == ' ' ){
			printf("\\b");
		}
		if( c == '\\' ){
			printf("\\");
		}
		putchar(c);
	}

	return 0;

}
