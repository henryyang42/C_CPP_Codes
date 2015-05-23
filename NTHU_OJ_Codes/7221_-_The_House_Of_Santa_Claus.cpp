#include <cstdio>

int adj[5][5] = {
		{0, 1, 1, 0, 1},
		{1, 0, 1, 0, 1},
		{1, 1, 0, 1, 1},
		{0, 0, 1, 0, 1},
		{1, 1, 1, 1, 0}
	};
int ans[10];
void dfs(int x, int len){
	ans[len] = x;
	if(len == 8){
		for(int i = 0; i < 9; i++)
			putchar('1' + ans[i]);
		putchar(10);
	}
	else{
		for(int i = 0; i < 5; i++)
			if(adj[x][i]){
				adj[x][i] = adj[i][x] = 0;
				dfs(i, len+1);
				adj[x][i] = adj[i][x] = 1;
			}
	}
}
int main(){
	dfs(0, 0);
	return 0;
}