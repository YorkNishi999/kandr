#include<stdio.h>
#define MAX 1000

int findc(char s1[], char s2[]);


int main()
{

	char a[MAX] = "ABCDEFGHIJKlmnopqrs";
	char c[MAX] = "CBGpA";


	printf("The char is %s.\n", a);
	printf("The delete char is %s.\n", c);

	int res = findc(a, c);
	
	printf("The answer is %d.\n", res);

	return 0;

}


int findc(char s1[MAX], char s2[MAX])
{
	int i, k;
	int ans; // ここの値が更新されていく
	ans = MAX;

	for (k = 0; s2[k] != '\0'; ++k) {
		for (i = 0; s1[i] != '\0'; ++i) {
			if (s1[i] == s2[k]) {
				ans = (ans < i) ? ans : i;
				}
		}
		//s1[j] = '\0'; // ＜この処理をいつ実施するかは結構重要
	}

	if(ans == MAX) ans = -1;

	return ans;
}

