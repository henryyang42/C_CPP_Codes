#include<cstdio>
#include<vector>
#include<queue>
#define MAX 100000000000LL
using namespace std;
int n, in[20001];
long long dis[20001];
vector<int> l[20001], d[20001];
long long SPFA(int st, int ed){
	queue<int> q;
	for(int i = 0; i <= n; i++)
		dis[i] = MAX, in[i] = 0;
	dis[st] = 0;
	q.push(st);
	while(!q.empty()){
		int x = q.front(); q.pop();
		in[x] = 0;
		for(int i = 0; i < l[x].size(); i++)
			if(dis[l[x][i]] > dis[x] + d[x][i]){
				dis[l[x][i]] = dis[x] + d[x][i];
				if(!in[l[x][i]])
					in[l[x][i]] = 1, q.push(l[x][i]);
			}
	}
	return dis[ed];
}
int main(){
	int t, m, st, ed, ct = 0;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &n, &m, &st, &ed);
		for(int i = 0; i <= n; i++)
			l[i].clear(), d[i].clear();
		while(m--){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			l[a].push_back(b);
			d[a].push_back(c);
			l[b].push_back(a);
			d[b].push_back(c);
		}
		long long ans = SPFA(st, ed);
		printf("Case #%d: ", ++ct);
		if(ans == MAX)
			puts("unreachable");
		else
			printf("%lld\n", ans);
	}
	return 0;
}
