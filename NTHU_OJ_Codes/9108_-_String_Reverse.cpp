#include<stdio.h>
#include<string.h>
char s[10000001];
int main(){
	while(gets(s) > 0){
		int l = strlen(s) - 1;
		while(l >= 0)
			putchar(s[l--]);
		putchar(10);
	}
	return 0;
}
