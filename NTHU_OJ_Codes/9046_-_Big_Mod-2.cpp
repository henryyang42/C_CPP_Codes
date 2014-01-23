#include<stdio.h>
int main(){
	long long int B, P, M;
	while(scanf("%lld%lld%lld", &B, &P, &M) > 0){
		long long int ans = 1, i;
		for(i = 0; (P >> i) && i < 32 ; i++)
			ans *= ((P >> i) & 1) ? B : 1, ans %= M, B = B * B, B %= M;
		printf("%lld\n", ans);
	}
	return 0;
}
