#include<stdio.h>

int main(){
	long long int a, b, c, d;
	while(scanf("%I64d%I64d", &a, &b) > 0){
		c = a, d = b;
		while(a > 0 && b > 0)
			if(a > b)
				a %= b;
			else
				b %= a;
			printf("%I64d\n", c * d / (a + b));	
	}
	return 0;
}
