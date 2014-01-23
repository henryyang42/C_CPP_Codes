#include<stdio.h>
int abs(int x){
	return x > 0 ? x : -x;
}
int t[101][101], dp[101][101], pre[101][101];
void print(int lv, int x){
	if(lv < 0)
		return;
	print(lv-1, pre[lv][x]);
	putchar('a' + x);
}
int main(){
	int n, m, s[101];
	while(scanf("%d%d", &n, &m) > 0){
		for(int i = 1; i <= 100; i++)
			for(int j = 0; j <= 100; j++)
				dp[i][j] = 1e9;
		for(int i = 1; i < n; i++)
			scanf("%d", &s[i]);
		for(int i = 0; i < m; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &t[i][j]);
		for(int k = 1; k < n; k++)
			for(int i = 0; i < m; i++)
				for(int j = 0; j < m; j++)
					if(dp[k-1][i] + abs(s[k] - t[i][j]) < dp[k][j]){
						pre[k][j] = i;
						dp[k][j] = dp[k-1][i] + abs(s[k] - t[i][j]);
					}
		int Min = 1e9, ind;
		for(int i = 0; i < m; i++)
			if(Min > dp[n-1][i])
				Min = dp[n-1][i], ind = i;
		print(n-1, ind);
		putchar(10);
	}
	return 0;
}
