#include<cstdio>
#define MOD 1000000000000LL
enum{ooo,oox,oxo,oxx,xoo,xox,xxo,xxx};
long long dp[3000][10];
int ct, n;

int main(){
	dp[1][ooo] = 1;
	dp[2][ooo] = 1;
	dp[2][oxo] = 1;
	dp[2][xox] = 1;
	dp[2][oxx] = dp[2][xxo] = 1;
	dp[2][xoo] = dp[2][oox] = 1;
	for(n = 3; n < 2001; n++){
		for(int i = 0; i < 7; i++)
			dp[n][ooo] += dp[n-1][i];
		dp[n][oox] = dp[n-2][ooo] + dp[n-2][xxo];
		dp[n][oxo] = dp[n-2][ooo] + dp[n-2][xox];
		dp[n][oxx] = dp[n-2][ooo] + dp[n-1][oox] + dp[n-3][oox];
		dp[n][xoo] = dp[n-2][ooo] + dp[n-2][oxx];
		dp[n][xox] = dp[n-2][ooo];
		dp[n][xxo] = dp[n-2][ooo] + dp[n-1][xoo] + dp[n-3][xoo];

		for(int i = 0; i < 7; i++)
			dp[n][i] %= MOD;
	}
	while(scanf("%d", &n), n)
		printf("Case %d: %lld\n", ++ct, dp[n][0]);
	return 0;
}
