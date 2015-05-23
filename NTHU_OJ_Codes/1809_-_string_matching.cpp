#include<cstdio>

int main(){
	unsigned long long a, b, r;
	while(scanf("%llu%llu", &a, &b) > 0){
		int ct = 0;
		r = 10;
		while(r <= b)
			r *= 10;
		while(a >= b){
			if(a % r == b)
				ct++;
			a /= 10;
		}
		printf("%d\n", ct);
	}
	return 0;
}
