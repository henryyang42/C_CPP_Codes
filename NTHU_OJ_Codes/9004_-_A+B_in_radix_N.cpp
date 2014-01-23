#include<stdio.h>
#include<string.h>
#define N 200
char s1[N], s2[N], ans[N], sradix[2];
int numize(char c){
	if(c >='0' && c <= '9')
		return c - '0';
	else
		return 10 + c - 'A';	
}
void reverse_add(char *p){
	int l = strlen(p), i;
	for(i = 0; i < l; i++)
		ans[i] += numize(*(p + l - 1 - i));
}
void out(int c){
	if(c < 10)
		putchar('0' + c);
	else
		putchar('A' + c - 10);
}
int main(){
	int i, radix, l;
	while(scanf("%d%s%s",&radix,s1,s2)>0){
		memset(ans, 0, sizeof(ans));
		reverse_add(s1);
		reverse_add(s2);
		for(i = 0; i < N; i++)
			ans[i + 1] += ans[i] / radix, ans[i] %= radix;
		l = N - 1;
		while(ans[l] == 0)
			l--;
		if(l < 0)
			printf("0");
		else
			for(i = l; i >=0; i--)
				out(ans[i]);
		putchar('\n');	
		
	}
    return 0;
}
