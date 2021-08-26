#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

//逆ポーランド電卓プログラム
int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push (pop() / op2);
				else 
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push(fmod(pop(), op2));
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}


char buf[BUFSIZE]; // ungetch buffer
int bufp = 0; // buf 内の次の空き位置

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ubgetch: too many characters\n");
	else
		buf[bufp++] = c;
}



// getop: 次の演算子あるいは数値の被演算数を取ってくる
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;  // 数ではない
	i = 0;
	if (c == '-') {
		s[i] = c;
		if (!isdigit(c = getch()))
			return '-';
		else
			s[++i] = c;
	}
	if (isdigit(c)) // 整数部を集める
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') // 小数部を集める
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;

}

#define MAXVAL 100 // max stack depth

int sp = 0; // stack pointer
double val[MAXVAL]; // value stack


// push
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack off, can't push %g\n", f);

}

// pop
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}

}

