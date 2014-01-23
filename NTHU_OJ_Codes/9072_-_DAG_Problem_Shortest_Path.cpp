#include<stdio.h>
#include<string.h>
int n, from, to, k, a, b, fg, l, ans[1001], temp[1001];
char adj[1001][1001];
void dfs(int x, int level){
	temp[level] = x;
	if(x == to){
		if(level < l)
			memcpy(ans, temp, sizeof(temp)), l = level, fg++;
		return;
	}
	int i;
	for(i = 0; i < n; i++)
		if(adj[x][i])
			dfs(i, level + 1);
}
int main(){
	int casect = 0;
	while(scanf("%d%d%d", &n, &from, &to) > 0, n + from + to){
		scanf("%d", &k);
		memset(adj, 0, sizeof(adj));
		while(k--)
			scanf("%d%d", &a, &b), adj[a][b] = 1;
		fg = 0, l = 10000000;
		dfs(from, 0);
		printf("Case %d: ", ++casect);
		if(fg){
			for(k = 0; k <= l; k++){
				if(k)
					putchar('-');
				printf("%d", ans[k]);
			}
			putchar(10);
		}
		else
			puts("INVALID");
	}
	return 0;
}
