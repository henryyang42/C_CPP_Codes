#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int n, w = 0;
	while(scanf("%d", &n), n){
		int s[100][30], sz[100] = {};
		for(int i = 1; i <= n; i++){
			scanf("%d", &sz[i]);
			for(int j = 1; j <= sz[i]; j++){
				scanf("%d", &s[i][j]);
			}
		}
		long long dp[100][2000] = {}, pre, Max = 0;
		for(int i = 0; i < 100; i++)
			for(int j = 1; j < 2000; j++)
				dp[i][j] = -1;
		for(int i = 1; i <= n; i++){
			pre = 0;
			for(int k = 0; k <= 1000; k++)
				if(dp[i-1][k] >= 0 && pre + dp[i-1][k] > dp[i][k])
					dp[i][k] = pre + dp[i-1][k];
			for(int j = 1; j <= sz[i]; j++){
				pre += 10LL - s[i][j];
				for(int k = 0; k <= 1000-j; k++)
					if(dp[i-1][k] >= 0 && pre + dp[i-1][k] > dp[i][k+j])
						dp[i][k+j] = pre + dp[i-1][k];
			}
		}
		vector<int> v;
		for(int i = 0; i < 2000;i++)
			Max = max(Max, dp[n][i]);
		for(int i = 0; i < 2000;i++)
			if(Max == dp[n][i])
				v.push_back(i);
		if(w++)
			putchar(10);
		printf("Workyards %d\n", w);
		printf("Maximum profit is %lld.\n", Max);
		printf("Number of pruls to buy:");
		int ct = 10 > v.size() ? v.size(): 10;
		for(int i = 0; i < ct; i++)
			printf(" %d", v[i]);
		putchar(10);
	}
	return 0;
}
