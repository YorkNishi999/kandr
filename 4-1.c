#include<stdio.h>
#define MAXLINE 1000

int ggetline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

// all search line for pattern matting
int main() 
{
	char line[MAXLINE];
	int found = 0;

	while (ggetline(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("starting index is %d\n",strindex(line, pattern));
			printf("%s", line);
			found++;
		}
	return found;

}


// ggetline: line into s, return length
int ggetline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;

}


// strindex: return index number starting t[] on s[]. if nothing, return -1.
int strindex(char s[], char t[])
{
	int i, j, k;
	
	for (i = 0; s[i] != '\0'; ++i) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) 
			;
		if (k > 0 && t[k] == '\0') {
			printf("i is %d.\n", i);
			return i;
		}

	}

	return -1;

}


