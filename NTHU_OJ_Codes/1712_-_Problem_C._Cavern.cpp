#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#define MAX 2147483648LL
using namespace std;
vector<int> l[100001], dist[100001];
long long dis[100001];
int visit[100001], pre[100001];
int t, n, m, k, p;
void SPFA(int st, int ed){
	queue<int> q;
	for(int i = 0; i <= n; i++)
		dis[i] = MAX, visit[i] = 0, pre[i] = -1;
	dis[st] = 0;
	q.push(st);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		visit[x] = 0;
		for(int i = 0; i < l[x].size(); i++){
			int to = l[x][i], d = dist[x][i];
			if(dis[to] > dis[x] + d){
				dis[to] = dis[x] + d;
				pre[to] = x;
				if(!visit[to]){
					q.push(to);
					visit[to] = 1;
				}
			}
			else if(dis[to] == dis[x] + d){
				if(pre[to] > x)
					pre[to] = x;
			}
		}
	}
	printf("%d", ed);
	while(pre[ed] != -1)
		printf("->%d", pre[ed]), ed = pre[ed];
	putchar(10);
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d", &n, &m, &k, &p);
        for(int i = 0; i <= n; i++)
			l[i].clear(), dist[i].clear();
        while(m--){
            int a, b, dis, c;
            scanf("%d%d%d", &a, &b, &dis);
            l[a].push_back(b);
            l[b].push_back(a);
            dist[a].push_back(dis);
            dist[b].push_back(dis);
        }
		SPFA(p, k);
    }
    return 0;
}

