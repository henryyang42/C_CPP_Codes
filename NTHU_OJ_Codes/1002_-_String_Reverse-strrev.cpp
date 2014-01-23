#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[1000001];
int main(){
	while(gets(s) > 0)
		strrev(s), puts(s);
	return 0;
}
