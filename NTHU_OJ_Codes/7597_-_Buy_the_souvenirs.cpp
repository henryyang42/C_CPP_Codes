#include<stdio.h>
#include<string.h>
int dp[40][600], x, n, m;
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		memset(dp, 0, sizeof(dp));
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++){
			scanf("%d", &x);
			for(int j = i; j > 0; j--)
				for(int k = m; k - x >= 0; k--)
					if(dp[j-1][k-x])
						dp[j][k] += dp[j-1][k-x];
			if(x <= m)
				dp[0][x]++;
		}
		int com, Max = 0;
		for(int j = n; j >= 0; j--){
			int temp = 0;
			for(int i = 0; i <= m; i++)
				temp += dp[j][i];
			if(temp){
				Max = temp, com = j;
				break;
			}
		}
		if(Max)
			printf("You have %d selection(s) to buy with %d kind(s) of souvenirs.\n", Max, com + 1);
		else
			puts("Sorry, you can't buy anything.");
	}
	return 0;
}
