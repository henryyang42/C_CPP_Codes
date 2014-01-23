#include<stdio.h>

int main(){
	long long n, m, N;
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld", &n, &m);
		N = n % m;
		long long ans = ((N*N*N) % m)*((N*N*N) % m) % m + 3*((N*N*N) % m)*((N*N) % m) % m - 2*N;
		ans %= m;
		ans += ((9 * (n*(n + 1))) / 2) % m;
		ans %= m;
		ans += 10*((((n*(n + 1)) / 2) )*(((n*(n + 1)) / 2) )) % m;
		ans %= m;
		ans -= (5*(((n)*(n+1)*(2*n+1))/2)  ) % m;
		ans %= m;
		if(ans < 0)
			ans += m;
		printf("%lld\n", ans / 6);
	}
	return 0;
}
