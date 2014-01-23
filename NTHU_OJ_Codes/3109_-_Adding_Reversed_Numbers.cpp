#include<stdio.h>
#include<string.h>
char s[300], t[300];

void reverse_(char s[]){
	int i, l = strlen(s);
	for(i = 0; i < l; i++)
		s[i] -= '0';
}
int main(){
	int n, i, start, end;
	scanf("%d", &n);
	while(n--){
		scanf("%s%s", s, t);
		reverse_(s), reverse_(t);
		for(i = 0; i < 300 - 1; i++)
			s[i] += t[i], s[i+1] += s[i] / 10, s[i] %= 10;
		for(start = 0; s[start] == 0; start++);
		for(end = 300 - 1; s[end] == 0; end--);
		for(i = start; i <= end; i++)
			putchar('0' + s[i]);
		putchar(10);
		for(i = 0; i < 300; i++)
			s[i] = t[i] = 0;
	}
	return 0;
}
