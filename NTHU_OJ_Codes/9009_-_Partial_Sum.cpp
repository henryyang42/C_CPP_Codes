#include<stdio.h>
int s[1000002];
long long  dp[1000002];

int main(){
	int t, n, a, b;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &s[i]), dp[i] = dp[i-1] + s[i];
		scanf("%d", &n);
		while(n--)
			scanf("%d%d", &a, &b), printf("%lld\n", dp[b] - dp[a] + s[a]);
	}
	return 0;
}
