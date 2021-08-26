#include<stdio.h>
#include<string.h>

void reverse(char s[]);

int main() 
{
	char a[] = "ABCDE";

	reverse(a);
	printf("%s\n", a);

}



void reverse(char s[])
{
	size_t n = strlen(s);
	static int i = 0;
	char tmp;


	if( i < (int) n / 2){
	 	tmp = s[i];
	 	s[i] = s[n-(i+1)];
	 	s[n-(++i)] = tmp;
	 	reverse(s);
	} else {	
	 	i = 0;
	}




}