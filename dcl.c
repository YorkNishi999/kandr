#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;						//最後のトークンの型
char token[MAXTOKEN];		//最後のトークン文字列
char name[MAXTOKEN];		//識別子
char datatype[MAXTOKEN];	//データ型＝charなど
char out[1000];						// 出力文字列

int main()
{
	while (gettoken() != EOF) {			//行の最初のトークンは
			strcpy(datatype, token);	//データ型である
			out[0] = '\0';
			dcl(); 				// 行の残りを解析
			if (tokentype != '\n')
				printf("syntax error \n");
			printf("success! %s: %s %s\n", name, out, datatype);
	}
	return 0;
}

int gettoken(void) // 次のトークンを返す
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;

	while ((c = getch()) == ' ' || c == '\t' )
		;
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; ) 
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else
	return tokentype = c;	
}


// dcl: 宣言子を解析する
void dcl(void)
{
	int ns;

	for (ns = 0; gettoken() == '*'; ) // *を数える
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}

// dirdcl: 直接の宣言子を解析する
void dirdcl(void)
{
	int type;

	if (tokentype == '(') {
		dcl();
		if (tokentype != ')') {
			printf("error: missing )\n");
		}
	} else if (tokentype == NAME) // variable name
		strcpy(name, token);
	else
		printf("error: expected name or (dcl)\n");
	while ((type =gettoken()) == PARENS || type == BRACKETS) {
		if (type == PARENS)
			strcat(out, " function returning");
		else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	}
}
