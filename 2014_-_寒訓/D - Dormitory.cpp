#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int dp[500][500], track[500][500][2]; //k, yesterday
int food[500];
vector<pair<int, int> > fri[500];
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, v, m;
	while(scanf("%d%d", &n, &v) > 0){
		memset(dp, -1, sizeof(dp));
		memset(track, 0, sizeof(track));
		for(int i = 0; i <= n; i++)
			fri[i].clear();
		for(int i = 1; i <= n; i++)
			scanf("%d", &food[i]);
		scanf("%d", &m);
		int f, t, w;
		for(int i = 1; i <= m; i++){
			scanf("%d%d%d", &f, &t, &w);
			for(int j = f; j <= t; j++)
				fri[j].push_back(make_pair(w, i));
		}
		for(int i = 1; i <= n; i++)
			sort(fri[i].begin(), fri[i].end());
		dp[0][0] = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= 400; j++)
				if(dp[i-1][j] >= 0){
					int caneat = food[i] - v + j;
					int remain = min(caneat, food[i]);
					if(dp[i][remain] < dp[i-1][j]){
						dp[i][remain] = dp[i-1][j];
						track[i][remain][0] = 0;
						track[i][remain][1] = j;
					}
					for(int k = 0; k < fri[i].size(); k++){
						caneat -= fri[i][k].first;
						if(caneat < 0)
							break;
						int remain = min(caneat, food[i]);
						if(dp[i][remain] < dp[i-1][j]+k+1){
							dp[i][remain] = dp[i-1][j]+k+1;
							track[i][remain][0] = k+1;
							track[i][remain][1] = j;
						}
					}
				}
		}
		int ans = 0, remain = 0;
		for(int i = 0; i <= 400; i++)
			if(ans < dp[n][i])
				ans = dp[n][i], remain = i;
		vector<int> tt[500];
		for(int i = n; i > 0; i--){
			//printf("%d", track[i][remain][0]);
			tt[i].push_back(track[i][remain][0]);
			for(int j = 0; j < track[i][remain][0]; j++){
				//printf(" %d", fri[i][j].second);
				tt[i].push_back(fri[i][j].second);
			}
			remain = track[i][remain][1];
			//putchar(10);
		}
		printf("%d\n", ans);
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < tt[i].size(); j++){
				if(j)
					putchar(32);
				printf("%d", tt[i][j]);
			}
			putchar(10);
		}
	}
	return 0;
}
