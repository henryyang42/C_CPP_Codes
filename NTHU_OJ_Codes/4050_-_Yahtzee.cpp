#include<cstdio>
#include<cstring>
#include<algorithm>
#define SIZE 8192
using namespace std;
int t[13][5], res[13][13];
int ans[15];
int dp[SIZE][64], track[SIZE][64][2];
void judge(int s[5], int temp[13]){
	int ct[6] = {0};
	/*ones to sixs, chances*/
	for(int i = 0; i < 5; i++)
		temp[s[i]-1] += s[i], temp[6] += s[i], ct[s[i]-1]++;
	/*kinds*/
	for(int i = 0; i < 6; i++){
		if(ct[i] >= 3)
			temp[7] = temp[6];
		if(ct[i] >= 4)
			temp[8] = temp[6];
		if(ct[i] == 5)
			temp[9] = 50;
	}
	/*short*/
	for(int i = 0; i < 3; i++)
		if(ct[i]&&ct[i+1]&&ct[i+2]&&ct[i+3])
			temp[10] = 25;
	/*long*/
	for(int i = 0; i < 2; i++)
		if(ct[i]&&ct[i+1]&&ct[i+2]&&ct[i+3]&&ct[i+4])
			temp[11] = 35;
	/*full house*/
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 6; j++)
			if(ct[i] == 2 && ct[j] == 3)
				temp[12] = 40;
}

int bit_ct(int n){
	int i, j;
	for(i = j = 0; i < 13; i++)
		j += 1&(n >> i);
	return j;
}

void run_dp(){
	dp[0][0] = 0;
	for(int i = 0; i < SIZE; i++)
		for(int k = 0; k < 13; k++)
			if(bit_ct(i) == k)
				for(int j = 0; j < 13; j++){
					if((i >> j)&1)
						continue;
					int score = res[k][j];
					int nstate = i | (1 << j);
					int six = j < 6 ? score : 0;
					for(int l = 0; l < 64; l++)
						if(dp[i][l] >= 0){
							int sixtot = l + six >= 63 ? 63 : l + six;
							if(dp[nstate][sixtot] < dp[i][l] + score){
								dp[nstate][sixtot] = dp[i][l] + score;
								track[nstate][sixtot][0] = j;//category
								track[nstate][sixtot][1] = l;//score
							}
						}
				}
		int mx = 0, bonus = 0, start = -1;
		for(int j = 0; j < 63; j++)
			if(mx < dp[SIZE-1][j])
				mx = dp[SIZE-1][j], start = j;
		if(dp[SIZE-1][63] >= 0 && mx < dp[SIZE-1][63] + 35)
				mx = dp[SIZE-1][63]+35, start = 63, bonus = 35;
		ans[13] = bonus, ans[14] = mx;
		int state = SIZE-1;
		for(int i = 12; i >= 0; i--){
			int cate = track[state][start][0];
			ans[cate] = res[i][cate];
			start = track[state][start][1];
			state ^= 1 << cate;
		}
}

int main(){
	while(scanf("%d%d%d%d%d", t[0], t[0]+1, t[0]+2, t[0]+3, t[0]+4) > 0){
		memset(ans, 0, sizeof(ans));
		memset(res, 0, sizeof(res));
		memset(dp, -1, sizeof(dp));
		for(int i = 1; i < 13; i++)
			scanf("%d%d%d%d%d", t[i], t[i]+1, t[i]+2, t[i]+3, t[i]+4);
		for(int i = 0; i < 13; i++)
			judge(t[i], res[i]);
		run_dp();
		printf("%d", ans[0]);
		for(int i = 1; i < 15; i++)
			printf(" %d", ans[i]);
		putchar(10);
	}
	return 0;
}
