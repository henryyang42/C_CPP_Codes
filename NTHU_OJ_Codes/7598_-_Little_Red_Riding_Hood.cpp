#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int, int> >l[50001];
int dis[50001], in[50001];
int main(){
	int t, n, m, a, b, c, d, sp;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &sp);
		for(int i = 0; i <= n; i++)
			l[i].clear(), dis[i] = 1e9, in[i] = 0;
		for(int i = 0; i < m; i++){
			scanf("%d%d%d.%d", &a, &b, &c, &d);
			l[a].push_back(make_pair(b, c*1000+d));
			l[b].push_back(make_pair(a, c*1000+d));
		}
		dis[1] = 0;
		queue<int> q;
		q.push(1);
		while(!q.empty()){
			int x = q.front();
			q.pop();
			in[x] = 0;
			for(int i = 0; i < l[x].size(); i++){
				int y = l[x][i].first, len = l[x][i].second;
				if(dis[y] > len + dis[x]){
					dis[y] = len + dis[x];
					if(!in[y])
						in[y] = 1, q.push(y);
				}
			}
		}
		if(dis[n] != 1e9) {
			char str[1000];
			sprintf(str, "%.3lf", (double)dis[n]/(double)sp);
			printf("%s sec(s), %d.%03d km.\n", str, dis[n] / 1000, dis[n] % 1000);
		}
		else
			puts("No way to old woman's house.");
	}
}
