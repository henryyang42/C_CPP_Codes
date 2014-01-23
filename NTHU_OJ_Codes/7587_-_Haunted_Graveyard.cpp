#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#define MAX 100000000000LL
using namespace std;
int n, m, st, ed, rec[50][50], neg_loop, holeto[1000], hole[1000];
long long dis[1000];
int dy[] = {1, 0,-1, 0};
int dx[] = {0, 1, 0,-1};
vector<int> l[1000], d[1000];
void SPFA(){
	int ct[1000] = {}, in[1000] = {};
	queue<int> q;
	for(int i = 0; i < n*m; i++)
		dis[i] = MAX*3;
	dis[st] = 0;
	q.push(st);
	while(!q.empty()){
		int x = q.front(); q.pop();
		in[x] = 0;
		for(int i = 0; i < l[x].size(); i++)
			if(dis[l[x][i]] > dis[x] + d[x][i]){
				dis[l[x][i]] = dis[x] + d[x][i];
				if(!in[l[x][i]]){
					if(ct[l[x][i]] > n*m){
						neg_loop = 1;
						return;
					}
					ct[l[x][i]]++;
					in[l[x][i]] = 1;
					q.push(l[x][i]);
				}
			}
	}
}
int main(){
	int x1, y1, x2, y2, t, q;
	while(scanf("%d%d", &n, &m), n+m){
		memset(rec, 0, sizeof(rec));
		for(int i = 0; i < n*m; i++)
			l[i].clear(), d[i].clear();
		scanf("%d", &q);
		while(q--)
			scanf("%d%d", &x1, &y1), rec[x1][y1] = 1;
		scanf("%d", &q);
		while(q--){
			scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &t);
			l[x1*m+y1].push_back(x2*m+y2);
			d[x1*m+y1].push_back(t);
			rec[x1][y1] = 2;
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)if(rec[i][j] == 0)
				for(int k = 0; k < 4; k++){
					int x = i + dx[k], y = j + dy[k];
					if(x >= 0 && y >= 0 && x < n && y < m && rec[x][y] != 1){
						l[i*m+j].push_back(x*m+y);
						d[i*m+j].push_back(1);
					}
				}
		neg_loop = 0;
		st = 0, ed = n*m-1;
		l[ed].clear();
		SPFA();
		if(neg_loop)
			puts("Never");
		else if(dis[ed] >= MAX)
			puts("Impossible");
		else
			printf("%lld\n", dis[ed]);
	}
	return 0;
}
