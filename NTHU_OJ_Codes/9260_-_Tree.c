#include<stdio.h>
int n;
char adj[1001][1001], visit[1001];
int main(){
	while(scanf("%d", &n), n){
		int a, b;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				adj[i][j] = 0;
		for(int i = 0; i < n; i++)
			scanf("%d%d", &a, &b), adj[a][b] = 1;
	}
	return 0;
}
