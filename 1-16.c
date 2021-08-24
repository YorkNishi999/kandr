#include<stdio.h>
#define MAXLINE 1000

int ggetline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len;								// # of present line 
	int max;								// # of max line
	char line[MAXLINE];			// input
	char longest[MAXLINE];	// the longest line set

	max = 0;
	while( (len = ggetline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0) // 行があった
		printf("longest sentense is %s, and logest number is", longest);
		printf("%d.\n", max);
	return 0;

}

// getline: 長さを返す
int ggetline(char s[], int lim)
{
	int c, i;
	
	for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c!='\n'; ++i) 
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;

}

// copy: fromをToにコピー、toは十分大きいと仮定
void copy(char to[], char from[]) 
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

