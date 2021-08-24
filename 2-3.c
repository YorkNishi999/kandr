#include<stdio.h>

int htoi(char s[]);

int main()
{

	int res;
	char a[] = "FFF";

	res = htoi(a);
	printf("The ans is %d.\n", res);

}


int htoi(char s[])
{

	int i, ans; // i は添字
	ans = 0; // これをリターンする。

	//for (i=0; s[i] >= '0' && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'F'; ++i )
	for (i=0; s[i] != '\0'; ++i )
		if ( s[i] >= '0' && s[i] <= '9' )
			ans = 16 * ans + (s[i] - '0');
		else
			ans = 16 * ans + (s[i] - 'A' + 10);

	return ans;

}

