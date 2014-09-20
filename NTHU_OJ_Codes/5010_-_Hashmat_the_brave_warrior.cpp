#include<stdio.h>
long long a, b;
int main(){
	while(scanf("%lld%lld", &a, &b) > 0)
		printf("%lld\n", a - b > 0 ? a - b : b - a);
	return 0;
}
