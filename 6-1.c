#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS 3

struct key {
	char *word;
	int count;
} ;

int getword( char *, int);
int binsearch( char *, struct key *, int);

//struct key keytab[NKEYS]; // keytab 内のキーワードの個数

struct key keytab[NKEYS] = {
	"auto", 0,
	"break", 0,
	"case", 0
};
// strcmpを使うので、この構造体のデータは、
// 辞書順になっている必要がある


// C のキーワードを数える
int main()
{
	int n;
	char word[MAXWORD];

	while (getword(word, MAXWORD) != EOF) 
		if (isalpha(word[0]))
			if ((n = binsearch( word, keytab, NKEYS)) >= 0)
				keytab[n].count++; 
	for (n = 0; n < NKEYS; n++) 
		if (keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
	return 0;
}

// binsearch tab[0] ... tab[n-1]の中の語を探す
int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;  // 2
	while ( low <= high ){ 
		mid = (low + high) / 2;  // mid = 1
		if (( cond = strcmp(word, tab[mid].word)) < 0) // aout とbreak < 0
		//	high = mid - 1; // high = 0;
			high = mid; // high = 0;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

// getword: 入力から次の語または文字を求める
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while(isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)){
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++){
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}
