
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<cstdio>
#define MAX 1e9
using namespace std;
int n, m, cap;
struct edge{
	int to, dis;
}E;
map<string, int> ma;
vector<edge> lis[10001], newlis[10001];
vector<int> v;
int visit[10001], dis[10001];
void SPFA(int st, int mode, vector<edge> lis[]){
	queue<int> q;
	for(int i = 0; i <= n; i++)
		dis[i] = MAX, visit[i] = 0;
	dis[st] = 0;
	q.push(st);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		visit[x] = 0;
		for(int i = 0; i < lis[x].size(); i++){
			int to = lis[x][i].to, d = lis[x][i].dis;
			if(dis[to] > dis[x] + d){
				dis[to] = dis[x] + d;
				if(!visit[to])
					q.push(to), visit[to] = 1;
			}
		}
	}
	if(mode)
		for(int i = 0; i < v.size(); i++)
			if(v[i] != st && dis[v[i]] <= 600){
				E.dis = 1;
				E.to = st;
				newlis[v[i]].push_back(E);
				E.to = v[i];
				newlis[st].push_back(E);
			}
}

int main(){
	while(cin >> n, n){
		for(int i = 0; i <= n; i++)
			lis[i].clear(), newlis[i].clear();
		int id = 1, d;
		v.clear();
		cin >> m;
		v.push_back(1), v.push_back(n);
		while(m--)
			cin >> cap, v.push_back(cap);
		cin >> m;
		while(m--){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			E.dis = c;
			E.to = a;
			lis[b].push_back(E);
			E.to = b;
			lis[a].push_back(E);
		}
		for(int i = 0; i < v.size(); i++)
			SPFA(v[i], 1, lis);
		SPFA(1, 0, newlis);
		if(dis[n] == MAX)
			puts("-1");
		else
			printf("%d\n", dis[n]-1);
	}
	return 0;
}
