#include<stdio.h>
char p[1000001];
int prime[1000001], pct;
int main(){
	for(int i = 2; i < 1000000; i++)
		if(p[i] == 0){
			prime[pct++] = i;
			for(int j = i * 2; j < 1000000; j += i)
				p[j] = 1;
		}
	int n, fg;
	while(scanf("%d", &n) > 0, n){
		fg = 0;
		for(int i = 0;	prime[i] < n; i++)
			if(!p[n - prime[i]]){
				printf("%d = %d + %d\n", n, prime[i], n - prime[i]);
				fg = 1;
				break;
			}
		if(!fg)
			puts("Goldbach's conjecture is wrong.");
	}
	return 0;
}
