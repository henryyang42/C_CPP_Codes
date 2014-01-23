#include<stdio.h>
#define MAX 10
int map[MAX][MAX], ct[MAX], count = 0, N = 8, max, test[MAX][MAX];
int check(){
	int i, j, temp;
	for(i = 0; i < N; i++){
		temp = 0, j = 0;
		while(i + j < N && j < N)
			temp += map[i + j][j], j++;
		if(temp > 1)
			return 0;
		temp = 0, j = 0;
		while(i + j < N && j < N)
			temp += map[j][i + j], j++;
		if(temp > 1)
			return 0;
		temp = 0, j = 0;
		while(i - j >= 0)
			temp += map[j][i - j], j++;
		if(temp > 1)
			return 0;
		temp = 0, j = 0;
		while(N - j - 1 >= 0 && i + j < N)
			temp += map[i + j][N - j - 1], j++;
		if(temp > 1)
			return 0;						
	}
	return 1;
}
void print(){
	int i, j, temp = 0;
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			temp += map[i][j] * test[i][j];
	if(temp > max)
		max = temp;
}
void dfs(int n){
	int i;
	if(n == N)
		return;
	for(i = 0; i < N; i++)
		if(ct[i] == 0){
			ct[i] = 1;
			map[n][i] = 1;
			if(n == N - 1){
				if(check())
					print(),count++;
			}
			dfs(n + 1);
			map[n][i] = 0;
			ct[i] = 0;	
		}
}
int main(){
	int t, i, j;
	while(scanf("%d", &t) > 0)
		while(t--){
			for(i = 0; i < N; i++)
				for(j = 0; j < N; j++)
					scanf("%d", &test[i][j]);
			max = 0;
			dfs(0);
			printf("%5d\n", max);
		}
    return 0;
}
