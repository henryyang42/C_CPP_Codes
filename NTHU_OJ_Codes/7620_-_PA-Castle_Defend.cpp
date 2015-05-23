#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t, v[100][100], pre[100], n, m, tct, tower[1000][2], stop, dp[100001];
void dfs(int x){
	for(int i = 1; i <= n && stop; i++)
		if(v[x][i] && !pre[i]){
			pre[i] = x;
			if(i == n)
				stop = 0;
			else
				dfs(i);
		}
}
int flow(){
	int ans = 0;
	while(1){
		stop = 1;
		memset(pre, 0, sizeof(pre));
		dfs(1);
		if(stop)
			return ans;
		int mini = 1e9;
		for(int i = n; i != 1; i = pre[i])
			mini = min(mini, v[pre[i]][i]);
		ans += mini;
		for(int i = n; i != 1; i = pre[i])
			v[pre[i]][i] -= mini, v[i][pre[i]] += mini;
	}
}
int main(){
	scanf("%d", &t);
	while(t--){
		memset(v, 0, sizeof(v));
		scanf("%d%d", &n, &m);
		int x, y, c;
		while(m--)
			scanf("%d%d%d", &x, &y, &c), v[x][y] = c;
		scanf("%d", &tct);
		for(int i = 0; i < tct; i++)
			scanf("%d%d", &tower[i][0], &tower[i][1]);
		int cap = flow();
		for(int i = 1; i <= 100000; i++)
			dp[i] = 1e9;
		for(int i = 0; i < tct; i++)
			for(int j = 0; j + tower[i][0] <= 100000; j++)
				dp[j+tower[i][0]] = min(dp[j+tower[i][0]], dp[j] + tower[i][1]);
		int ans = 1e9;
		for(int i = cap; i <= 100000; i++)
			ans = min(ans, dp[i]);
		printf("%d\n", ans);
	}
	return 0;
}
