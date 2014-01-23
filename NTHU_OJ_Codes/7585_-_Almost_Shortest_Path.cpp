#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int n, m, st, ed;
vector<int> l[510], d[510], to_delete[510];
int adj[510][510];
int SPFA(int st, int ed){
	int dis[510], in[510] = {0};
	queue<int> q;
	for(int i = 0; i < n; i++)
		dis[i] = 1e9;
	dis[st] = 0;
	q.push(st);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		in[x] = 0;
		for(int i = 0; i < l[x].size(); i++)
			if(adj[x][l[x][i]] && dis[l[x][i]] > dis[x] + adj[x][l[x][i]]){
				dis[l[x][i]] = dis[x] + adj[x][l[x][i]];
				if(!in[l[x][i]])
					q.push(l[x][i]), in[l[x][i]] = 1;
				to_delete[l[x][i]].clear();
				to_delete[l[x][i]].push_back(x);
			}
			else if(adj[x][l[x][i]] && dis[l[x][i]] == dis[x] + adj[x][l[x][i]]){
				to_delete[l[x][i]].push_back(x);
			}
	}
	return dis[ed];
}
int visit[510];
void dfs(int x){
	visit[x] = 1;
	for(int i = 0; i < to_delete[x].size(); i++)
		if(!visit[to_delete[x][i]]){
			adj[to_delete[x][i]][x] = 0;
			dfs(to_delete[x][i]);
		}
}
int main(){
	while(scanf("%d%d", &n, &m), m + n){
		scanf("%d%d", &st, &ed);
		for(int i = 0; i < n; i++)
			l[i].clear(), d[i].clear(), to_delete[i].clear(), visit[i] = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				adj[i][j] = 0;
		while(m--){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			l[a].push_back(b);
			d[a].push_back(c);
			adj[a][b] = c;
		}
		SPFA(st, ed);
		dfs(ed);
		int ans = SPFA(st, ed);
		printf("%d\n", ans == 1e9 ? -1 : ans);
	}
	return 0;
}
