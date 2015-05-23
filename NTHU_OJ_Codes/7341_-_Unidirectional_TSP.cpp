#include<stdio.h>
int n, m, s[100][100], temp[100], ans[100], min, di[] = {1, 0, -1};
void dfs(int i, int j, int w){
	if(j < m && min < w) return;
	if(j == m){
		if(min == w){
			int k = 0;
			min = w;
			while(temp[k] == ans[k])
				k++;
			if(temp[k] < ans[k])
				for(k = 0; k < m; k++)
					ans[k] = temp[k];
		}
		if(min > w){
			int k = 0;
			min = w;
			for(k = 0; k < m; k++)
				ans[k] = temp[k];
		}
		return;
	}
	for(int k = 0; k < 3; k++)
		temp[j] = i+1, dfs((i + di[k] + n) % n, j + 1, w + s[i][j]);
}
int main(){
	while(scanf("%d%d", &n, &m) > 0){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &s[i][j]);
		min = 2147483647;
		for(int i = 0; i < m; i++)
			ans[i] = min;
		dfs(0, 0, 0);
		printf("%d", ans[0]);
		for(int i = 1; i < m; i++)
			printf(" %d", ans[i]);
		putchar(10);
		printf("%d\n", min);
	}
	return 0;
}
