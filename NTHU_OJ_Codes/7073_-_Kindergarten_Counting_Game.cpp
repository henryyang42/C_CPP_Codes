#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[100000];
int main(){
	while(gets(s) > 0){
		int ct = 0, l = strlen(s), i, fg = 0;
		for(i = 0; i < l; i++){
			if(!fg && isalpha(s[i]))
				ct++, fg = 1;
			if(!isalpha(s[i]))
				fg = 0;
		}
		printf("%d\n", ct);
	}
	return 0;
}
