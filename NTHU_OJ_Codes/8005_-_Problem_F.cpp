#include<stdio.h>
#include<string.h>
int main(){
	char s[100];
	while(gets(s) > 0){
		for(int i = strlen(s) - 1; i >= 0; i--)
			putchar(s[i]);
		putchar(10);
	}
	return 0;
}
