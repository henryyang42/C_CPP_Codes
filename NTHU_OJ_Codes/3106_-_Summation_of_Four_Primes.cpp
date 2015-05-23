#include<stdio.h>
char prime[10000001];
int p[10000001], pct;
int main(){
	for(int i = 2; i < 10000000; i++)
		if(!prime[i]){
			for(int j = 2 * i; j < 10000000; j += i)
				prime[j] = 1;
			p[pct++] = i;
		}
	int n, fg;
	while(scanf("%d", &n) > 0){
		fg = 0;
		if(n < 8)
			puts("Impossible.");
		else{
			n -= 4;
			for(int i = 0; p[i] < n; i++)
				if(!prime[n-p[i]]){
					printf("2 2 %d %d\n", p[i], n - p[i]);
					fg = 1;
					break;
				}
			n--;
			if(!fg)
				for(int i = 0; p[i] < n; i++)
				if(!prime[n-p[i]]){
					printf("2 3 %d %d\n", p[i], n - p[i]);
					fg = 1;
					break;
				}
		}
	}
	return 0;
}

