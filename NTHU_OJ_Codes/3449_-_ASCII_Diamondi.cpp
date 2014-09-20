#include<stdio.h>
int abs(int x){
	return x > 0 ? x : -x;
}
char pos(int n, int x, int y){
	x = abs(x % (2*n-1) - (n-1));
	y = abs(y % (2*n-1) - (n-1));
	if((x + y) >= n)
		return '.';
	return (((x + y) % n) % 26) + 'a';
}
int main(){
	int n, x1, x2, y1, y2, ct = 0;
	while(scanf("%d%d%d%d%d", &n, &x1, &y1, &x2, &y2), n){
		printf("Case %d:\n", ++ct);
		for(int x = x1; x <= x2; x++, putchar(10))
			for(int y = y1; y <= y2; y++)
				putchar(pos(n, x, y));
	}
	return 0;
}
