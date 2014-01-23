#include<cstdio>
long long dp[5][30001], coin[] = {1, 5, 10, 25, 50};
int main(){
	int n;
	for(int i = 0; i < 30001; i++)
		dp[0][i] = 1;
	for(int i = 1; i < 5; i++){
		for(int j = 0; j < coin[i]; j++)
			dp[i][j] = dp[i-1][j];
		for(int j = coin[i]; j <= 30000; j++)
			dp[i][j] = dp[i-1][j] + dp[i][j-coin[i]];
	}
	while(scanf("%d", &n) > 0){
		if(dp[4][n] == 1)
			printf("There is only 1 way to produce %d cents change.\n", n);
		else
			printf("There are %lld ways to produce %d cents change.\n", dp[4][n], n);
	}
	return 0;
}
