#include<cstdio>
#define MOD 100000007
#define ULL unsigned long long
ULL pow[65][2][2] = {{{1, 1}, {1, 0}}};
void times(ULL s[2][2], ULL t[2][2], ULL ans[2][2]){
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++){
			ULL x = 0;
			for(int k = 0; k < 2; k++)
				x += s[i][k] * t[k][j];
			ans[i][j] = x % MOD;
		}
}
int main(){
	for(int i = 1; i <=64; i++)
		times(pow[i-1], pow[i-1], pow[i]);
	ULL n;
	while(scanf("%llu", &n) > 0){
		ULL ans[2][2] = {{1, 0}, {0, 1}}, temp[2][2];
		for(int i = 0; i < 64; i++)
			if((n >> i) & 1){
				times(ans, pow[i], temp);
				for(int j = 0; j < 2; j++)
					for(int k = 0; k < 2; k++)
						ans[j][k] = temp[j][k];
			}
		printf("%llu\n", (ans[1][0]) % MOD);
	}
	return 0;
}
