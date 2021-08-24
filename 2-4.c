#include<stdio.h>
#define MAX 1000
void squeeze(char s1[], char s2[]);


int main()
{

	char a[MAX] = "ABCDEFGHIJKlmnopqrs";
	char c[MAX] = "BCGpg";


	printf("The char is %s.\n", a);
	printf("The delete char is %s.\n", c);

	squeeze(a, c);
	
	printf("The squeezed char is %s.\n", a);

	return 0;

}


void squeeze(char s1[MAX], char s2[MAX])
{
	int i, j, k;

	for (k = 0; s2[k] != '\0'; ++k) {
		for (i = j = 0; s1[i] != '\0'; ++i) {
			if (s1[i] != s2[k]) {
				s1[j] = s1[i];
				j++;
				}
			printf("k, i, j, is %d, %d, %d.\n", k, i, j);
			printf("s of k, i, j, is %c, %c, %c.\n", s2[k], s1[i], s1[j]);
		}
		s1[j] = '\0'; // ＜この処理をいつ実施するかは結構重要
	}

}

