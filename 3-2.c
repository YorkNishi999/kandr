#include <stdio.h>
#define BUFFER 1000
void escape(char s[], char t[]);

int main()
{
	int i, c;
	char s[BUFFER], t[BUFFER];

	for (i=0; i<BUFFER-1 && (c=getchar()) != EOF; ++i)
		s[i] = c;
	s[i] = '\0';

	escape(s,t);
	printf("%s\n", t);
	return 0;
	
}

void escape(char s[], char t[])
{

	int i, j;
	i = j = 0;

	for (i = 0; s[i] != '\0'; ++i) {
		switch (s[i]) {
				case '\n':
					t[i+j] = '\\';
					t[i+j+1] = 'n';
					++j;
					break;
				case '\t':
					t[i+j] = '\\';
					t[i+j+1] = 't';
					++j;
					break;
				default:
					t[i+j] = s[i];
					++j;
					break;
			}
	}
	t[i+j] = '\0';
	
}
