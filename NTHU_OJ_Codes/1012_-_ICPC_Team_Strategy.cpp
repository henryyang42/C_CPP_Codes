#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int time[3][15], t, n;
int dp[1<<12][1<<3][300], d[] = {0, 1, 2, 4};
int bit_ct(int x){
	int j = 0;
	for(int i = 0; i < n; i++)
		j += (x>>i)&1;
	return j;
}
int main(){
	scanf("%d", &t);
	while(t--){
		int ans = 0;
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < n; j++)
				scanf("%d", &time[i][j]);
		int M = 1<<n;
		for(int num = 0; num < n; num++) //solved
			for(int que = 0; que < n; que++) //question
				for(int state = 0; state < M; state++) //state
					if(bit_ct(state) == num && !(1&(state>>que))){ //que not solved
							int nstate = state|(1<<que);
							for(int k = 0; k < 4; k++)
								for(int cost = 0; cost <= 280; cost++)
									//if(dp[state][d[k]][cost] >= 0)
										for(int player = 0; player < 3; player++) //choose player
											if(!(1&(d[k] >> player)) && cost + time[player][que] <= 280)
												dp[nstate][1<<player][cost + time[player][que]] = max(dp[nstate][1<<player][cost + time[player][que]], dp[state][d[k]][cost]+1);

					}
		for(int i = 0; i < 3; i++)
			for(int j = 0; j <= 280; j++)
				ans = max(ans, dp[M-1][1<<i][j]);
		printf("%d\n", ans);
	}
	return 0;
}
