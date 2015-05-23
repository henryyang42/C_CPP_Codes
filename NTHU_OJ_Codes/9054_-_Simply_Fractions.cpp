#include<stdio.h>
int gcd(int a, int b){
	while(a > 0 && b > 0)
		if(a > b)
			a %= b;
		else
			b %= a;
	return a + b;
}
int a, b, c, d, e;
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		d = a < 0 ? -a : a;
		e = b < 0 ? -b : b;
		if(a < 0 && b < 0)
			a = -a, b = -b;
		c = gcd(d, e);
		printf("%d/%d\n", a / c, b / c);
	}
    return 0;
}
