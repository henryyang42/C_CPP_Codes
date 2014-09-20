#include<stdio.h>
struct Num{
	long long up, low;
}s[100];
int t, n;
long long GCD(long long a, long long b){
	while(a && b)
		if(a > b)
			a %= b;
		else
			b %= a;
	return a + b;
}
inline void up(int r){
	s[r].low = s[r<<1].low*s[r<<1|1].low;
	s[r].up = s[r<<1].up*s[r<<1|1].low + s[r<<1].low*s[r<<1|1].up;
	long long gcd = GCD(s[r].low, s[r].up);
	s[r].low /= gcd;
	s[r].up /= gcd;
}
void build(int L, int R, int r){
	if(L == R){
		scanf("%lld", &s[r].low);
		s[r].low *= n;
		s[r].up = 1;
	}
	else{
		int mid = (L + R) >> 1;
		build(L, mid, r<<1);
		build(mid+1, R, r<<1|1);
		up(r);
	}
}
int main(){
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d", &n);
		build(1, n, 1);
		printf("Case %d: %lld/%lld\n", i, s[1].low, s[1].up);
	}
	return 0;
}

