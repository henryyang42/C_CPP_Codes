#include<stdio.h>
#include<string.h>
#define N 1001
bool map[N][N], ct[N];
int ans;
void dfs(int n){
	int i, tot = 0;
	if(ct[n])
		return;
	ct[n] = 1;
	for(i = 1; i < N; i++)
		if(map[n][i] && !ct[i])
			tot++, dfs(i);
	if(tot == 0)
		ans++;
}
int main(){
	int t, i, a, b;
	while(scanf("%d", &t) > 0, t){
		ans = 0;
		memset(map, 0, sizeof(map));
		memset(ct, 0, sizeof(ct));
		while(t--)
			scanf("%d%d", &a, &b), map[a][b] = 1, map[b][a] = 1;
		scanf("%d", &a);
		dfs(a);
		printf("%d\n", ans);
	}
    return 0;
}
