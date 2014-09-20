#include<stdio.h>
#include<string.h>
char adj[201][201], isvisit[201];
int n, fg;
void dfs(int x, int color){
	isvisit[x] = color;
	int i;
	for(i = 0; i < n; i++)
		if(adj[x][i] && !isvisit[i])
			dfs(i, color == 1 ? 2 : 1);
		else if(adj[x][i] && color == isvisit[i])
			fg = 1;
}
int main(){
	int a, b, q;
	while(scanf("%d", &n), n){
		scanf("%d", &q);
		memset(adj, 0, sizeof(adj));
		memset(isvisit, 0, sizeof(isvisit));
		while(q--)
			scanf("%d%d", &a, &b), adj[a][b] = adj[b][a] = 1;
		fg = 0;
		dfs(0, 1);
		if(fg)
			puts("NOT BICOLORABLE.");
		else
			puts("BICOLORABLE.");
	}
	return 0;
}
