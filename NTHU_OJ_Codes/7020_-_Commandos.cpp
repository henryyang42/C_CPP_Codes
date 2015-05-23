#include<stdio.h>
#include<string.h>
int min(int a, int b){
	return a > b ? b : a;
}
int max(int a, int b){
	return a < b ? b : a;
}
int main(){
	int t, ct = 0;
	scanf("%d", &t);
	while(t--){
		int ans = 0, n, r, start, end, adj[101][101];
		memset(adj, 10000, sizeof(adj));
		scanf("%d%d", &n, &r);
		for(int i = 0; i < n; i++)
			adj[i][i] = 0;
		for(int i = 0; i < r; i++)
			scanf("%d%d", &start, &end), adj[start][end] = adj[end][start] = 1;
		scanf("%d%d", &start, &end);
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					adj[i][j] = min(adj[i][k] + adj[k][j], adj[i][j]);
		/*for(int i = 0; i < n; i++, puts(""))
				for(int j = 0; j < n; j++)
					printf("%d ", adj[i][j]);*/
		for(int i = 0; i < n; i++)
			ans = max(ans, adj[start][i] + adj[i][end]);
		printf("Case %d: %d\n", ++ct, ans);
	}
	return 0;
}
