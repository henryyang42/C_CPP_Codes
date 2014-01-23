#include<cstring>
#include<cstdio>
char s[20][20];
long long dp[1<<20];
int t, n, ct;
int bit_ct(int x){
	int j = 0;
	for(int i = 0; i < 2*n; i++)
		j += (x>>i) & 1;
	return j;
}
bool can(int x, int state){
	for(int i = 0; i < 2*n; i++)
		if(!(1&(state>>i)) && s[x][i] == 'Y')
			return false;
	return true;
}
int main(){
	scanf("%d", &t);
	while(t--){
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		int M = 1 << (2*n);
		for(int j = 0; j < 2*n; j++)
			scanf("%s", s[j]);
		dp[0] = 1;
		for(int i = 0; i < M; i++)
			for(int k = 0; k < n; k++)
				if(bit_ct(i) == k)
					for(int j = 0; j < 2*n; j++){
						if(!(1&(i>>j)) && can(j, i)){
							dp[i|(1<<j)] += dp[i];
						}
					}
		long long ans = 0;
		for(int i = 0; i < M; i++)
			if(bit_ct(i) == n){
				ans += dp[i]*dp[i^(M-1)];
			}
		printf("%lld\n", ans);
	}
	return 0;
}

