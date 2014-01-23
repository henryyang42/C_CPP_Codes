#include<stdio.h>
#include<string.h>
double cost[101], val[101];
double dp[101][101][2];
int state[101][101], pre[101][101], ct;
void print(int day, int x){
	if(day < 1)
		return;
	print(day - 1, pre[day][x]);
	if(day != 1)
		putchar(32);
	printf("%d", x+1);
}
int main(){
	int n, k, fg = 0;
	double m;
	while(scanf("%d%d%lf", &k, &n, &m) > 0, k + n + m){
		memset(dp, 0, sizeof(dp));
		memset(state, 0, sizeof(state));
		for(int i = 0; i < n; i++)
			scanf("%lf%lf", &cost[i], &val[i]);
		for(int day = 1; day <= k; day++){
			if(day == k) m++;
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++){
					if(i != j){
						if(dp[day-1][j][0] + val[i] > dp[day][i][0] && dp[day-1][j][1] + cost[i] < m){
							dp[day][i][0] = dp[day-1][j][0] + val[i];
							dp[day][i][1] = dp[day-1][j][1] + cost[i];
							//state[day][i] = 0;
							pre[day][i] = j;
						}
						else if(dp[day-1][j][0] + val[i] == dp[day][i][0] && cost[i] + dp[day-1][j][1] < dp[day][i][1] && dp[day-1][j][1] + cost[i] < m){
							dp[day][i][0] = dp[day-1][j][0] + val[i];
							dp[day][i][1] = dp[day-1][j][1] + cost[i];
							//state[day][i] = 0;
							pre[day][i] = j;
						}
					}
					else{
						double value = val[i] - (val[i] / 2) * (state[day-1][j] <= 2 ? state[day-1][j] : 2);
						if(dp[day-1][j][0] + value > dp[day][i][0] && dp[day-1][j][1] + cost[i] < m){
							dp[day][i][0] = dp[day-1][j][0] + value;
							dp[day][i][1] = dp[day-1][j][1] + cost[i];
							state[day][i] = state[day-1][j] + 1;
							pre[day][i] = j;
						}
						else if(dp[day-1][j][0] + value == dp[day][i][0] && cost[i] + dp[day-1][j][1] < dp[day][i][1] && dp[day-1][j][1] + cost[i] < m){
							dp[day][i][0] = dp[day-1][j][0] + value;
							dp[day][i][1] = dp[day-1][j][1] + cost[i];
							state[day][i] = state[day-1][j] + 1;
							pre[day][i] = j;
						}
					}
				}
			if(day == k) m--;
		}
			/*for(int i = 1; i <= k; i++, puts(""))
				for(int j = 0; j < n; j++)
					printf("(%.1lf %.1lf) ", dp[i][j][0], dp[i][j][1]);*/
			int ind = -1;
			double Max = -1, Cost = 1e9;
			for(int i = 0; i < n; i++)
				if(Max < dp[k][i][0])
					Max = dp[k][i][0], Cost = dp[k][i][1], ind = i;
				else if(Max == dp[k][i][0] && Cost > dp[k][i][1])
					Max = dp[k][i][0], Cost = dp[k][i][1], ind = i;
			if(ct++)
				putchar(10);
			if(ind == -1 || Cost > m){
				puts("0.0");
			}
			else{
				printf("%.1lf\n", Max);
				print(k, ind);
				putchar(10);
			}
	}
	return 0;
}
