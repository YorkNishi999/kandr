#include<stdio.h>

void swap(char *v[], int i, int j);


void swap (char *v[], int i, int j)
{
	char *tmp;

	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
	
}