#include<stdio.h>
#include<ctype.h>
char s[1000000];
int main(){
	while(gets(s) > 0){
		int i, j;
		for(i = 0; s[i]; i++){
			int tot = 0;
			if(s[i] == '!'){
				putchar(10);
				continue;	
			}
			while(isdigit(s[i]))
				tot += s[i++] - 48;
			if(s[i] == 'b')
				s[i] = ' ';
			for(j = 0; j < tot; j++)
				putchar(s[i]);
		}
		putchar(10);	
	}
	return 0;
}
