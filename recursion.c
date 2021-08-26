#include <stdio.h>

void printd(int);
// printd: n を１０進で表記

int main() {
	int n;

	n = 12345;
	printd(n);

	return 0;
}


void printd(int n) 
{
	//負の数の処理
	if (n < 0) {
		putchar('-');
		n = -n;
	}

	// 再帰で書く
	if (n > 0){
		printd( n / 10);
		putchar(n%10 + '0');
	}

}