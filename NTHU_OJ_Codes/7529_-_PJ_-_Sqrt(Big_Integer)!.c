#include<stdio.h>
#include<string.h>
int main(){
	char s[10001];
	while(scanf("%s", s) > 0){
		if(strcmp(s, "0") == 0)return 0;
		int r, l = strlen(s), i = 0, l0;
		if(l % 2 == 0)
			r = (s[0]-48)*10 + s[1]-48, l0 = (l-2) / 2;
		else
			r = s[0]-48, l0 = (l-1)/2;
		while(i*i <= r)
			i++;
		i--;
		putchar('0'+i);
		while(l0-->0)
			putchar('0');
		putchar(10);
	}
	return 0;
}
