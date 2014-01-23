#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int adj[30][30], n, m, c;
void print(int pre[], int x, int lv){
	if(x == -1)
		return;
	print(pre, pre[x], lv+1);
	putchar('A' + x);
	if(lv)
		putchar(32);
}
void SPFA(int st, int ed){
	queue<int> q;
	int pre[30], visit[30] = {0}, ct[30] = {0}, dis[30];
	for(int i = 0; i < n; i++)
		dis[i] = 1e9;
	pre[st] = -1;
	dis[st] = 0;
	q.push(st);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		visit[x] = 0;
		for(int i = 0; i < n; i++)
			if(adj[x][i]){
				if(dis[i] > dis[x] + adj[x][i]){
					dis[i] = dis[x] + adj[x][i];
					ct[i] = ct[x] + 1;
					pre[i] = x;
					if(!visit[i])
						q.push(i), visit[i] = 1;
				}
				else if(dis[i] == dis[x] + adj[x][i] && ct[i] > ct[x] + 1){
					ct[i] = ct[x] + 1;
					pre[i] = x;
				}
			}
	}
	print(pre, ed, 0);
	putchar(10);
}
int main(){
	while(scanf("%d%d", &n, &m) > 0){
		char a[2], b[2];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				adj[i][j] = 0;
		while(m--)
			scanf("%s%s%d", a, b, &c), adj[a[0]-'A'][b[0]-'A'] = adj[b[0]-'A'][a[0]-'A'] = c;
		scanf("%d", &m);
		while(m--)
			scanf("%s%s", a, b), SPFA(a[0]-'A', b[0]-'A');
	}
	return 0;
}
