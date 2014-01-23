#include<stdio.h>
char prime[1000001], dprime[1000001];
int dp[1000001];
int isdprime(int x){
	int digit = 0;
	while(x > 0)
		digit += x % 10, x /= 10;
	return !prime[digit];
}
int main(){
	for(int i = 2; i < 1000000; i++)
		if(!prime[i])
			for(int j = 2 * i; j < 1000000; j += i)
				prime[j] = 1;
	for(int i = 2; i < 1000000; i++)
		if(!prime[i] && isdprime(i))
			dprime[i] = 1;
	for(int i = 2; i <= 1000000; i++)
		dp[i] = dp[i-1] + dprime[i];
	int n, a, b;
	scanf("%d", &n);
	while(n--)
		scanf("%d%d", &a, &b), printf("%d\n", dp[b] - dp[a] + dprime[a]);
	return 0;
}
