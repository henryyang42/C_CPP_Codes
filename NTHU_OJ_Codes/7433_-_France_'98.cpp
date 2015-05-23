#include<stdio.h>
using namespace std;
char name[16][100];
int adj[16][16];
double dp[5][16];
int main(){
	for(int i = 0; i < 16; i++)
		scanf("%s", name[i]), dp[0][i] = 1.0;
	for(int i = 0; i < 16; i++)
		for(int j = 0; j < 16; j++)
			scanf("%d", &adj[i][j]);
	for(int stage = 1; stage <= 4; stage++)
		for(int i = 0; i < 16; i++){
			int district = (i / (1 << stage)) * (1 << stage);
			for(int j = district; j < district + (1 << stage); j++)
				if(i / (1 << (stage-1)) != j / (1 << (stage-1))){
					dp[stage][i] += dp[stage-1][i] * dp[stage-1][j] * adj[i][j] / 100.0;
				}
		}
	for(int i = 0; i < 16; i++){
		printf("%-10s p=%.2lf%%\n", name[i], dp[4][i]*100.0);
	}
	return 0;
}
