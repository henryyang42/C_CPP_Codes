#include<stdio.h>
#define MOD 32767
long long int ans[1001];
int main(){
	int i, j;
	for(ans[1] = 1, ans[2] = 2, ans[3] = 5, ans[0] = 1, i = 4; i <= 1000; i++){
		for(j = 0; j <= i; j++)
			ans[i] += (ans[j] * ans[i - j - 1]) % MOD;
		ans[i] %= MOD;
	}
	while(scanf("%d", &i) > 0)
		printf("%d\n", ans[i]);
	return 0;
}
