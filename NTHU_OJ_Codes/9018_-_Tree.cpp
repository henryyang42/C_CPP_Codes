#include<stdio.h>
#include<string.h>
char map[1001][1001] = {0}, ct[1001] = {0};
int fg;
void dfs(int a){
	if(fg++)
		putchar(32);
	ct[a] = 1;
	printf("%d", a);
	int i;
	for(i = 0; i < 1001; i++)
		if(map[a][i] && !ct[i])
			dfs(i);
}
int main(){
	int n, i, a, b;
	while(scanf("%d", &n) > 0, n){
		fg = 0;
		memset(map, 0, sizeof(map));
		memset(ct, 0, sizeof(ct));
		for(i = 0; i < n; i++){
			scanf("%d%d", &a, &b);
			map[a][b] = 1;
		}
		scanf("%d", &a);
		dfs(a);
		putchar(10);
	}
	return 0;
}
