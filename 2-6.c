#include <stdio.h>
unsigned getbits(unsigned x, int p, int n);
void binary(int);

int main()
{

	unsigned xx; 
	xx = 15;

	int p = 3;
	int n = 2;

	unsigned ans;

	ans = getbits(xx, p, n);

	printf("10: %d,16: %x.\n", xx, xx);
	printf("2: ");
	binary(xx);
	printf(".\n");
	printf("10: %d,16: %x.\n", ans, ans);
	printf("2: ");
	binary(ans);
	printf(".\n");


	printf("10: %d, 16: %x.\n", ~0, ~0);
	int aa = ~0;
	binary(aa);
	printf(".\n");
	aa = aa << n;
	binary(aa);
	printf(".\n");
	aa = ~aa;	
	binary(aa);
	printf(".\n");
	
	
	
	return 0;


}

// ｐの位置からｎビット取ってくる
unsigned getbits(unsigned x, int p, int n)
{
	return ( x >> (p + 1 - n)) & ~(~0 << n);
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
