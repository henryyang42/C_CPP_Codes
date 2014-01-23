#include<stdio.h>
int n, N, ct;
char adj[1001][1001];
void dfs(int x){
	if(ct++)
		putchar(32);
	printf("%d", x);
	for(int i = 1; i <= N; i++)
		if(adj[x][i])
			dfs(i);
}
int main(){
	while(scanf("%d", &n), n){
		int a, b;
		ct = N = 0;
		for(int i = 0; i <= 1000; i++)
			for(int j = 0; j <= 1000; j++)
				adj[i][j] = 0;
		for(int i = 0; i < n; i++){
			scanf("%d%d", &a, &b), adj[a][b] = 1;
			N = N < a ? a : N;
			N = N < b ? b : N;
		}
		scanf("%d", &a);
		dfs(a);
		putchar(10);
	}
	return 0;
}
