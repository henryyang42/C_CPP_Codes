#include<stdio.h>

int main(){
	unsigned long long fib[100] = {1, 1, 2}, n, nn;
	for(int i = 3; i < 100; i++)
		fib[i] = fib[i-1] + fib[i-2];
	while(scanf("%llu", &n) > 0){
		int s[100], ct = 0;
		nn = n;
		for(int i = 92; i >= 0; i--){
			if(n >= fib[i])
				n -= fib[i], s[ct++] = i;
		}
		printf("%llu\n%d", nn, s[0]);
		for(int i = 1; i< ct; i++)
			printf(" %d", s[i]);
		printf("\n%llu", fib[s[0]]);
		for(int i = 1; i < ct; i++)
			printf(" %llu", fib[s[i]]);
		puts("\n");
	}
	return 0;
}
