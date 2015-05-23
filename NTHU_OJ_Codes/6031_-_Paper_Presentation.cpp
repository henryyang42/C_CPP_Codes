#include <cstdio>

int bit(int x){
	int ans = 0;
	for(int i = 0; i < 32; i++)
		ans += 1&(x>>i);
	return ans;
}

int main(){
	int t, n;
	scanf("%d", &t);
	while(t--){
		int dp[1<<17] = {0}, ans = 0;
		char s[20][20];
		scanf("%d", &n);
		for(int i = 0; i < 2*n; i++)
			scanf("%s", s[i]);
		dp[0] = 1;
		for(int i = 0; i < n; i++)
			for(int x = 0; x < 1<<(2*n); x++)
				if(bit(x) == i)
					for(int j = 0; j < 2*n; j++)
						if((1&(x>>j)) == 0){
							int fg = 1;
							for(int k = 0; k < 2*n; k++)
								fg = fg && (s[j][k] == 'N' || s[j][k] == 'Y' && (1&(x>>k)));
							if(fg)
								dp[x|(1<<j)] += dp[x];
						}
		for(int i = 0; i < 1<<(2*n); i++)
			if(bit(i) == n){
				ans += dp[i]*dp[(1<<2*n)-i-1];
			}
		printf("%d\n", ans);
	}
	return 0;
}