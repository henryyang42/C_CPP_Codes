#include<stdio.h>
long long int LCM_(long long int a, long long int b){
	long long int c = a, d = b;
	while(a && b)
		if(a > b)
			a %= b;
		else
			b %= a;
	return c * d / (a + b);
}
int main(){
	int t, n, i, ct = 0;
	long long int LCM, a, b;
	while(scanf("%d", &t) > 0)
		while(t--){
			scanf("%d", &n);
			scanf("%lld %lld", &a, &b);
			LCM = LCM_(a, b);
			for(i = 0; i < n - 2; i++)
				scanf("%lld", &a), LCM = LCM_(LCM, a);
			printf("Case %d: %lld\n", ++ct, LCM);
		}
	return 0;
}
