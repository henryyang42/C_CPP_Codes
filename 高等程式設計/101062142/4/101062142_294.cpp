#include <cstdio>
#include <cmath>
int prime[3300], pct = 0;
char p[33000];
int _count(int x){
	int sq = sqrt(x), ans = 1, ct;
	for(int i = 0; x > 1 && sq >= prime[i]; i++){
		ct = 1;
		while(x % prime[i] == 0)
			ct++, x /= prime[i];
		ans *= ct;
	}
	return x > 1 ? ans<<1 : ans;
}
int main(){
	for(int i = 2; i < 32000; i++)
		if(!p[i]){
			prime[pct++] = i;
			for(int j = i<<1; j < 32000; j += i)
				p[j] = 1;
		}
	int t;
	scanf("%d", &t);
	while(t--){
		int a, b;
		scanf("%d%d", &a, &b);
		int Max = 0, num = 0;
		for (int i = a; i <= b; ++i){
			int ct = _count(i);
			if(ct > Max)
				Max = ct, num = i;
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", a, b, num, Max);
	}
	return 0;
}