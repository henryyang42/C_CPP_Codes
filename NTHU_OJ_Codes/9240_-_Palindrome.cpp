#include<stdio.h>
#include<string.h>
char s[100001];
int main(){
	while(scanf("%s",s) > 0){
		int l = strlen(s), i, j, fg;
		for(fg = 0, i = 0, j = l - 1; i < j; i++, j--)
			if(s[i] != s[j]){
				fg = 1;
				break;	
			}
			if(fg == 1)
				puts("No");
			else
				puts("Yes");
	}
    return 0;
}
