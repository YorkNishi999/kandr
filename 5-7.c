#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qqsort(char *lineptr[], int left, int right);

// 入力行をソートする
int main() 
{
	int nlines; // 読み込まれた入力行の数

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qqsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000 //任意の入力行の最大長
int ggetline(char s[], int i);
char *alloc(int);

// readline: 入力行を読み込む
int readlines(char *lineptr[], int maxlines) 
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = ggetline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; //改行を消す
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

// writelines: 出力行を書き出す
void writelines(char *lineptr[], int nlines)
{
	int i;
	for (i = 0; i < nlines; i++) 
		printf("%s\n", lineptr[i]);
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

// qsort:
void qqsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right)
		return; //配列の要素が２より少ないときは何もしない
	swap( v, left, (left + right)/2);
	last = left;
	for (i = left + 1; i <= right; ++i) {
		if  (strcmp(v[i], v[left]) < 0) 
			swap(v, ++last, i);
	}
	swap(v, left, last);
	qqsort(v,left, last-1);
	qqsort(v, last+1, right);
}


