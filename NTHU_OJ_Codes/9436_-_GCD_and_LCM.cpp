#include<stdio.h>
long long gcd(long long x, long long y){
	while(x && y)
		if(x > y)
			x %= y;
		else
			y %= x;
	return x + y;
}
long long lcm(long long x, long long y){
	return x*y/gcd(x, y);
}
int main(){
	int n;
	long long x, y, z;
	scanf("%d", &n);
	while(n--){
		scanf("%lld%lld%lld", &x, &y, &z);
		long long GCD = gcd(x, gcd(y, z));
		printf("%lld %lld\n",GCD, lcm(x, lcm(y, z)));
	}
	return 0;
}
