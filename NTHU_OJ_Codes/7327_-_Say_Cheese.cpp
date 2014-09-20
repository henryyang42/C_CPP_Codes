#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int n, ct;
struct ball{
	double x, y, z, r;
}B[10001];
struct edge{
	int to;
	double dis;
}E;
vector<edge> lis[101];
double SPFA(int st, int ed){
	double dis[101];
	int visit[101] = {0};
	queue<int> q;
	for(int i = 0; i < n + 2; i++)
		dis[i] = 1e9;
	dis[st] = 0;
	q.push(st);
	while(!q.empty()){
		int x = q.front(); q.pop();
		visit[x] = 0;
		for(int i = 0; i < lis[x].size(); i++){
			int to = lis[x][i].to;
			double d = lis[x][i].dis;
			if(dis[to] > dis[x] + d){
				dis[to] = dis[x] +d;
				if(!visit[to])
					q.push(to), visit[to] = 1;
			}
		}
	}
	return dis[ed];
}

int main(){
	while(scanf("%d", &n), n+1){
		for(int i = 0; i < n + 2; i++)
			lis[i].clear();
		for(int i = 0; i < n; i++)
			scanf("%lf%lf%lf%lf", &B[i].x, &B[i].y, &B[i].z, &B[i].r);
		scanf("%lf%lf%lf%", &B[n].x, &B[n].y, &B[n].z);
		scanf("%lf%lf%lf%", &B[n+1].x, &B[n+1].y, &B[n+1].z);
		B[n].r = B[n+1].r =0;
		for(int i = 0; i < n + 2; i++)
			for(int j = 0; j < n + 2; j++){
				E.dis = sqrt((B[i].x-B[j].x)*(B[i].x-B[j].x) + (B[i].y-B[j].y)*(B[i].y-B[j].y) +(B[i].z-B[j].z)*(B[i].z-B[j].z)) - B[i].r - B[j].r;
				if(E.dis < 0)
					E.dis = 0;
				E.to = j;
				lis[i].push_back(E);
				E.to = i;
				lis[j].push_back(E);
			}
		printf("Cheese %d: Travel time = %.0lf sec\n", ++ct, 10*SPFA(n, n+1));
	}
	return 0;
}
