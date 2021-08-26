#include <stdio.h>
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

