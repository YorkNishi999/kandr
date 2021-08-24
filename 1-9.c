#include<stdio.h>

int main() 
{

	int c, ns, prev_c;
	
	ns = 0;

	while( (c = getchar() ) != EOF) {
		if( c != ' ' || prev_c != ' ' ) {
			putchar(c);
			prev_c = c;
		}
	}

	return 0;

}
