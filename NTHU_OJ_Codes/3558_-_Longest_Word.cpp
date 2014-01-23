#include<stdio.h>
#include<ctype.h>
#include<string.h>
int Max, ct;
char c, ans[1000], buffer[1000];
int main(){
	while((c = getchar()) > 0){
		if(isalpha(c) || c == '-')
			buffer[ct++] = c;
		else
			ct = 0;
		if(ct > Max){
			Max = ct;
			strcpy(ans, buffer);
		}
	}
	for(int i = 0; i < Max; i++)
		ans[i] = tolower(ans[i]);
	ans[Max] = 0;
	puts(ans);
	return 0;
}
