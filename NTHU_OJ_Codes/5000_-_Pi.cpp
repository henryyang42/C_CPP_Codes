#include<stdio.h>
#include<math.h>
int isprime(int a, int b){
	while(a > 0 && b > 0)
		if(a > b)
			a %= b;
		else
			b %= a;
	if(a + b == 1)
		return 1;
	return 0;	
}
int main(){
	int n, s[51], i, j, tot;
	while(scanf("%d", &n) > 0, n){
		for(i = 0; i < n; i++)
			scanf("%d", &s[i]);
		tot = 0;
		for(i = 0; i < n; i++)
			for(j = i + 1; j < n; j++)
				tot += isprime(s[i], s[j]);
		if(tot == 0)
			puts("No estimate for this data set.");
		else
			printf("%lf\n", sqrt(3.0 * n * (n - 1) / tot));			
	}
	return 0;	
}
