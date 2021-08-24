#include <stdio.h>
unsigned getbits(unsigned x, int p, int n);
void binary(int);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n); 

int main()
{

	unsigned xx; 
	xx = 15;

	int p = 3;
	int n = 2;

	unsigned ans, ans2, ans3;

	ans = getbits(xx, p, n);

	printf("10: %d,16: %x.\n", xx, xx);
	printf("2: ");
	binary(xx);
	printf(".\n");
	printf("10: %d,16: %x.\n", ans, ans);
	printf("2: ");
	binary(ans);
	printf(".\n");


	ans2 = invert(xx, p, n);
	
	printf("ｐからｎビット取ってきて反転\n");
	printf("10: %d,16: %x.\n", xx, xx);
	printf("2: ");
	binary(xx);
	printf(".\n");
	printf("10: %d,16: %x.\n", ans2, ans2);
	printf("2: ");
	binary(ans2);
	printf(".\n");

	ans3 = rightrot(xx, n);
	
	printf("ｎビット回転\n");
	printf("10: %d,16: %x.\n", xx, xx);
	printf("2: ");
	binary(xx);
	printf(".\n");
	printf("10: %d,16: %x.\n", ans3, ans3);
	printf("2: ");
	binary(ans3);
	printf(".\n");
	
	
	return 0;


}

// ｐの位置からｎビット取ってくる
unsigned getbits(unsigned x, int p, int n)
{
	return ( x >> (p + 1 - n)) & ~(~0 << n);
}

// pの位置からnビット取ってきて反転
unsigned invert(unsigned x, int p, int n)
{
	unsigned mask, invertmask;

	mask = (~(~0 << p + 1)) ^ ~(~0 << p - n + 1); 
	printf("mask is");
	binary(mask);
	printf("\n");
	invertmask = ~mask;

	return ( x & ~mask ) | ( x & invertmask);
	//return ( x & mask );
}

// nビット回転
unsigned rightrot(unsigned x, int n) 
{
	return ( x >> n ) | (( x & (~(~0 << n ))) << (8 - n));
}

// 10進数を２進数に
void binary(int x) 
{
	unsigned bit = ( 1 << (sizeof(int) * 2 - 1 ));
	
	for( ;bit != 0; bit >>= 1){
		if (x & bit) {
			putchar('1');
		} else {
			putchar('0');
		}
	}

}
