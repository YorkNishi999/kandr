#include<ctype.h>
#include<stdio.h>
#define MAXLINE 100

double atof(char s[]);
int ggetline(char line[], int max);

int main() {

	double sum;
	char line[MAXLINE];

	sum = 0;
	while (ggetline(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));
	
	return 0;

}

// atof: char s into float

double atof(char s[])
{
	double val, power, p;
	int i, sign;
	int josuu = 0;

	p = 1.0;

	for (i = 0; isspace(s[i]); ++i)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-' )
		i++;
	for (val = 0.0; isdigit(s[i]); ++i)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); ++i) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	if (s[i] == 'e' || s[i] == 'E'){
		i++;
	}
	switch (s[i++]) {
		case '+': 
			for (josuu = 0; isdigit(s[i]); ++i) {
				josuu += (s[i] - '0');
			for (p = 1.0; josuu > 0; --josuu)
				p *= 10.0;
				printf("in p is %f.\n", p);
			}
			break;
		case '-':
			for (josuu = 0; isdigit(s[i]); ++i) {
				josuu += (s[i] - '0');
			for (p = 1.0; josuu > 0; --josuu)
				p *= 0.1;
				printf("in p is %f.\n", p);
			}
			break;
	}
	printf("out p is %f.\n", p);
	//return sign * val * p / power;
	return sign * val * p / power ;

}
