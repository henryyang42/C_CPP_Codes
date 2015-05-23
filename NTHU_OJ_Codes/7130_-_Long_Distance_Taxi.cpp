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
vector<edge> lis[2011], newlis[2011];
vector<int> v;
int visit[2011], dis[2011];
void SPFA(int st, int mode, vector<edge> lis[]){
	queue<int> q;
	for(int i = 0; i <= 2000; i++)
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
			if(v[i] != st && dis[v[i]] <= cap*10){
				E.dis = dis[v[i]];
				E.to = st;
				newlis[v[i]].push_back(E);
				E.to = v[i];
				newlis[st].push_back(E);
			}
}

int main(){
	while(cin >> n >> m >> cap, n + m + cap){
		for(int i = 0; i <= 2000; i++)
			lis[i].clear(), newlis[i].clear();
		int id = 1, d;
		string s, t;
		ma.clear();
		v.clear();
		cin >> s >> t;
		ma[s] = id++, ma[t] = id++;
		while(n--){
			cin >> s >> t >> d;
			if(ma.find(s) == ma.end())
				ma[s] = id++;
			if(ma.find(t) == ma.end())
				ma[t] = id++;
			int a = ma[t], b = ma[s];
			E.dis = d;
			E.to = b;
			lis[a].push_back(E);
			E.to = a;
			lis[b].push_back(E);
		}
		v.push_back(1), v.push_back(2);
		while(m--)
			cin >> s, v.push_back(ma[s]);
		for(int i = 0; i < v.size(); i++)
			SPFA(v[i], 1, lis);
		SPFA(v[0], 0, newlis);
		if(dis[v[1]] == MAX)
			puts("-1");
		else
			printf("%d\n", dis[v[1]]);
	}
	return 0;
}
