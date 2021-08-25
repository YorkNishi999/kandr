#include <stdio.h>
#define MAX 100

void expand(char s1[], char s2[]);

int main() 
{

	char a[MAX] = "a-z";
	char b[MAX];

	
	expand(a, b);
	printf("before: %s\n", a);
	printf("expand: %s\n", b);

}


void expand(char s1[], char s2[])
{
	int i, j, k, diff;
	char tmp[MAX];

	i = j = k = diff = 0;
	
	for (i = 0; s1[i] != '\0'; ++i) {
		if(s1[i] == '-') {
			++j;
			continue;
		}
		tmp[i-j] = s1[i]; // tmp[] = 'az';
	} // end of for

	diff = tmp[1] - tmp[0];
	//printf("%d\n", diff);

	for (k = 0; k <= diff; ++k) {
		s2[k] = tmp[0] + k;
		//printf("%d\n", s2[k]);
	}

	s2[k] = '\0';
	
}

