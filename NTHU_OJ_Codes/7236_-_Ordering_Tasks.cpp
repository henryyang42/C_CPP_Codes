#include<stdio.h>
#include<string.h>
char adj[101][101], visit[101];
int n;
int stack[101], sz;
void dfs(int x){
	visit[x] = 1;
	int j;
    for(j = 1; j <= n; j++)
        if(adj[x][j] && !visit[j])
            dfs(j);
	stack[sz++] = x;
}
int main(){
	int a, b, q, i;
	while(scanf("%d%d", &n, &q) > 0, n + q){
		memset(adj, 0, sizeof(adj));
		memset(visit, 0, sizeof(visit));
		while(q--)
			scanf("%d%d", &a, &b), adj[a][b] = 1;
		for(i = n, sz = 0; i > 0; i--)
			if(!visit[i])
				dfs(i);
		printf("%d", stack[--sz]);
		while(--sz >= 0)
			printf(" %d", stack[sz]);
		putchar(10);
	}
	return 0;
}
