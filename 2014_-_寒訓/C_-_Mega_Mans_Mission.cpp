#include<cstring>
#include<cstdio>
char s[20]; //s[i][j] = '1' if i can kill j
long long dp[1<<20];
int t, n, ct, atk[20];

int main(){
	scanf("%d", &t);
	while(t--){
		memset(atk, 0, sizeof(atk));
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		scanf("%s", s);
		int initweapon = 0, M = 1 << n;
		for(int i = 0; i < n; i++)
			if(s[i] == '1')
				initweapon |= 1 << i;
		for(int j = 0; j < n; j++){
			scanf("%s", s);
			for(int i = 0; i < n; i++)
				if(s[i] == '1')
					atk[j] |= 1 << i;
		}

		dp[0] = 1;
		for(int i = 0; i < M; i++){
			int weapon = initweapon;
			for(int j = 0; j < n; j++)
				if(1&(i>>j))
					weapon |= atk[j];
			for(int j = 0; j < n; j++)
				if(!((i>>j)&1) && (1&(weapon>>j)))
					dp[i|(1<<j)] += dp[i];
		}

		printf("Case %d: %lld\n", ++ct, dp[M-1]);
	}
	return 0;
}
