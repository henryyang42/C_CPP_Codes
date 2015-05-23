#include<stdio.h>
int leader[1000];
int adj[1000][1000];
int ans[50001][2];
int find_(int x){
	while(leader[x] != x)
		x = leader[x];
	return x;
}
int main(){
	int n, m, a, b, i, j, ct;
	while(scanf("%d%d", &n, &m) > 0){
		/*for(i = 0; i <= n; i++)
			leader[i] = i;*/
		for(i = 0; i <= n; i++)
			for(j = 0; j <= n; j++)
				adj[i][j] = 0;
		for(i = 0, ct = 0; i < m; i++){
			scanf("%d%d", &a, &b);
			/*int fa = find_(a), fb = find_(b);
			if(fa != fb){
				ans[ct][0] = a, ans[ct++][1] = b;
				leader[fa] = fb;
			}*/
			if(adj[a][b] == 0 && a != b)
				ans[ct][0] = a, ans[ct++][1] = b, adj[a][b] = adj[b][a] = 1;
		}
		printf("%d %d\n", n, ct);
		for(i = 0; i < ct; i++)
			printf("%d %d\n", ans[i][0], ans[i][1]);
		putchar(10);
	}
	return 0;
}
