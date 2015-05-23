#include<stdio.h>
char s[1000][1000];
int di[] = {1,-1,0,1,0,-1,-1,1};
int dj[] = {1,-1,1,0,-1,0,1,-1};
void dfs(int i, int j){
	s[i][j] = 0;
	for(int k = 0; k < 8; k++)
		if(s[di[k]+i][dj[k]+j] == '#')
			dfs(di[k]+i, dj[k]+j);
}
int main(){
	int n, m;
	while(scanf("%d%d", &n, &m), n+m){
		getchar();
		for(int i = 1; i <= n; i++)
			gets(s[i]+1);
		int ct = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				if(s[i][j] == '#')
					ct++, dfs(i, j);
		printf("%d\n", ct);
	}
	return 0;
}
