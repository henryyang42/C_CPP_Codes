#include<stdio.h>
int dp[1000001] = {0};
int c(unsigned long long n){
	int cycle = 0;
	while(n > 1){
		cycle++;
		if(n & 1)
			n = 3 * n + 1;
		else
			n >>= 1;
	}
	return cycle;
}
int f(unsigned long long int n){
	if(n == 1 || n > 1000000)
		return c(n);
	if(dp[n])
		return dp[n];
	if(n & 1)
		return (dp[n] = f(3 * n + 1) + 1);
	else
		return (dp[n] = f(n >> 1) + 1);
}

int main(){
	int n, i;
	char s[10];
	while(gets(s) > 0){
		for(i = n = 0; s[i]; i++)
			n = n * 10 + s[i] - 48;
		printf("%d\n", f(n));
	}
	return 0;
}
