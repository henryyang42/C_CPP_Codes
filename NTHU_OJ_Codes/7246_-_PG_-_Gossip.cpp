#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int adj[1001][1001], secret = 0, n, m, a, b, visit[1001];
void dfs(int x, int color){
	if(secret) return;
	visit[x] = color;
	for(int i = 1; i <= n; i++)
		if(adj[x][i] && !visit[i])
			dfs(i, color == 1 ? 2 : 1);
		else if(adj[x][i] && visit[i] == color)
			secret = 1;
}
int main(){
    while(scanf("%d", &n) > 0, n){
		memset(adj, 0, sizeof(adj));
		memset(visit, 0, sizeof(visit));
		secret = 0;
        scanf("%d", &m);
        while(m--){
        	scanf("%d%d", &a, &b);
			adj[a][b] = adj[b][a] = 1;
        }
        for(int i = 1; i <= n; i++)
        	if(!visit[i])
        		dfs(i, 1);
        if(secret)
            puts("You discover a BIG Secret!!");
        else
            puts("Successful");
    }
    return 0;
}

