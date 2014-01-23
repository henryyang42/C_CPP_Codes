#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
#include<vector>
using namespace std;
const int M = 1<<16;
vector<int> sum[1025*10];
vector<int> bit4;
int pair8[1000000][2], pair8ct;
int s[100], ct;
long long dp[M+1];
int bit_ct(int x){
	int i, j;
	for(i = j = 0; i < 16; i++)
		j += 1&(x >> i);
	return j;
}
int main(){
	for(int i = 0; i < M; i++)
		if(bit_ct(i) == 4)
			bit4.push_back(i);
	for(int i = 0; i < bit4.size(); i++)
			for(int j = i+1; j < bit4.size(); j++)
				if(bit_ct(bit4[i]|bit4[j]) == 8)
					pair8[pair8ct][0] = bit4[i], pair8[pair8ct++][1] = bit4[j];
	while(scanf("%d", &s[0]), s[0]){
		for(int i = 0; i < 10250; i++)
			sum[i].clear();
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i < 16; i++)
			scanf("%d", &s[i]);
		sort(s, s+16);
		for(int i = 0; i < M; i++)
			if(bit_ct(i) == 4){
				int arr[5], ind = 0;
				for(int j = 0; j < 16; j++)
					if(1&(i >> j))
						arr[ind++] = s[j];
				do{
					int x = 0;
					for(int k = 0; k < 4; k++)
						x += (k+1)*arr[k];
					sum[x].push_back(i);
				}while(next_permutation(arr, arr+4));
			}
		for(int i = 0; i < 10250; i++)
			for(int j = 0; j < sum[i].size(); j++)
				for(int k = j+1; k < sum[i].size(); k++)
					if(bit_ct(sum[i][j]|sum[i][k]) == 8)
						dp[sum[i][j]|sum[i][k]]++;
		long long int ans = 0;
		for(int i = 0; i < M; i++)
			if(bit_ct(i) == 8){
				ans += dp[i]*dp[i^(M-1)];
			}
		printf("Case %d: %lld\n", ++ct, ans/2);
	}
	return 0;
}
