#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[1001][1001], t, n, remain[1001] = {}, d[1001], price[1001], ans;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d%d%d", &price[i], &remain[i], &d[i]);
		for(int i = 1; i <= n; i++)
			for(int j = 0; j <= 101; j++)
				dp[i][j] = 1e9;
		for(int i = 1; i <= n; i++)
			for(int j = 0; j <= d[i]; j++) //get from today
					if(remain[i-1] >= d[i]-j && remain[i] >= j)
					for(int k = 0; k <= ((remain[i-1] - d[i] + j) > 100 ? 100 : (remain[i-1] - d[i] + j)); k++){
						dp[i][j] = min(dp[i][j], dp[i-1][k] + j*price[i] + (d[i]-j)*price[i-1]);
					}
		ans = 1e9;
		for(int i = 0; i <= 100; i++)
			ans = min(ans, dp[n][i]);
		printf("%d\n", ans);
	}
	return 0;
}
