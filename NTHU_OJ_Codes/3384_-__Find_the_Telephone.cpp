#include<stdio.h>
#include<ctype.h>
char s[100];
int main(){
	while(gets(s) > 0){
		for(int i = 0; s[i]; i++)
			if(isalpha(s[i]))
				putchar("22233344455566677778889999"[s[i] - 'A']);
			else
				putchar(s[i]);
		putchar(10);
	}
	return 0;
}
