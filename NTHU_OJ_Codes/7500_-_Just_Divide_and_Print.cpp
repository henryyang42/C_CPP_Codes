#include<stdio.h>
int digits(int x){
	int i = 0;
	while(x)
		i++, x /= 10;
	return i;	
}
void spaces(int x, char c){
	while(x--)
		putchar(c);	
}
int gcd(int a, int b){
	while(a && b)
		if(a > b)
			a %= b;
		else
			b %= a;
	return a + b;	
}
int main(){
	int i, ct = 0, tot, n, x;
	while(scanf("%d", &n) > 0, n){
		for(i = 0, tot = 0; i < n; i++)
			scanf("%d", &x), tot += x;
		printf("Case %d:\n", ++ct);
		if(tot % n == 0){
			if(tot >= 0)
				printf("%d\n", tot / n);
			else
				printf("- %d\n", (-tot) / n);
		}
		else{
			if(tot >= 0){
				int a = tot / n, b = n, c = tot % n;
				int GCD = gcd(c, b);
				b /= GCD, c /= GCD;
				int la = digits(a), lb = digits(b), lc = digits(c);
				int max = lb > lc ? lb : lc;
				spaces(la + max - lc, ' ');
				printf("%d\n", c);
				if(a)
					printf("%d", a);
				spaces(max, '-');
				putchar(10);
				spaces(la + max - lb, ' ');
				printf("%d\n", b);
			}
			else{
				int a = (-tot) / n, b = n, c = (-tot) % n;
				int GCD = gcd(c, b);
				b /= GCD, c /= GCD;
				int la = digits(a), lb = digits(b), lc = digits(c);
				int max = lb > lc ? lb : lc;
				spaces(la + max - lc + 2, ' ');
				printf("%d\n", c);
				if(a)
					printf("- %d", a);
				else
					printf("- ");
				spaces(max, '-');
				putchar(10);
				spaces(la + max - lb + 2, ' ');
				printf("%d\n", b);
			}
		}
	}
	return 0;
}
