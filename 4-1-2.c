#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

int ggetline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char s[], char t[]);

char pattern[] = "ould";

// all search line for pattern matting
int main() 
{
	char line[MAXLINE];
	int found = 0;

	//while (ggetline(line, MAXLINE) > 0)
	//	if (strindex(line, pattern) >= 0) {
	//		printf("%s", line);
	//		printf("The first matting is %d\n.", strindex(line,pattern));
	//		found++;
	//	}
		
	while (ggetline(line, MAXLINE) > 0)
		if (strrindex(line, pattern) >= 0) {
			printf("The last matting is %d.\n", strrindex(line,pattern));
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
		if (k > 0 && t[k] == '\0')
			return i;
	}

	return -1;

}

// strrindex: return the right index number starting t[] on s[]. or -1.
int strrindex(char s[], char t[])
{
	int i, j, k;
	
	for (i = strlen(s)-1; i != 0; --i) {
		for (j = i, k = strlen(pattern)-1; k != 0 && s[j] == t[k]; --j, --k) 
			;
		if (k == 0){
			return i-strlen(pattern);
		}
	}

	return -1;

}

