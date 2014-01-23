#include<stdio.h>
#include<string.h>
int adj[101][101], ans[101], ct[101], n, max, temp[101], whites[101];
void dfs(int dep, int black, int white){
	if(dep == n + 1 || black + white == n){
		if(max < black)
			memcpy(ans, temp, sizeof(ans)), max = black;
		return;
	}
	if(whites[dep] == 0){
		int white_temp[101], index = 0, i, newwhite = white;
		temp[black] = dep;
		for(i = 0; i < ct[dep]; i++)
			if(whites[adj[dep][i]] == 0)
				whites[adj[dep][i]] = 1, newwhite++, white_temp[index++] = adj[dep][i];
		dfs(dep + 1, black + 1, newwhite);
		for(i = 0; i < index; i++)
			whites[white_temp[i]] = 0;
	}
	dfs(dep + 1, black, white + !whites[dep]);
}
int main(){
	int t, x, y, i, q;
	scanf("%d", &t);
	while(t--){
		memset(whites, 0, sizeof(whites));
		memset(ct, 0, sizeof(ct));
		scanf("%d%d", &n, &q);
		while(q--)
			scanf("%d%d", &x, &y), adj[x][ct[x]++] = y, adj[y][ct[y]++] = x;
		max = 0;
		dfs(1, 0, 0);
		printf("%d\n", max);
		for(i = 0; i < max - 1; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[i]);
	}
	return 0;
}
