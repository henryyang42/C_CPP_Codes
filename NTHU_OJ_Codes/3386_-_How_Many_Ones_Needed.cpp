#include<stdio.h>

int main(){
	long long a, b, i, ans, ct = 0;
	while(scanf("%lld%lld", &a, &b) > 0, a + b){
		for(i = ans = 0; i < 31; i++){
			long long da = ((a + 1) % (1 << (i + 1))) - (1 << i), db = ((b + 1) % (1 << (i + 1))) - (1 << i);
			ans += (a >> i) & 1;
			ans += ((b + 1) / (1 << (i + 1))) * (1 << i)
			+ ((db > 0) ? db: 0);
			ans -= ((a + 1) / (1 << (i + 1))) * (1 << i)
			+ ((da > 0) ? da: 0);
		}
		printf("Case %lld: %lld\n", ++ct, ans);
	}
	return 0;
}
