#include<stdio.h>
char prime[1000001] = {0};
int ans [1000001] = {0};
int main(){
	int i, j, n, t;
	for(prime[0] = 1, prime[1] = 1, i = 2; i <= 1000000; i++)
		if(!prime[i])
			for(j = i * 2; j <= 1000000; j += i)
				prime[j] = 1;
	for(i = 1; i <= 1000000; i++)
		ans[i] = ans[i - 1] + !prime[i];
	while(scanf("%d", &t) > 0)
		while(t--){
			scanf("%d", &n);
			printf("%d\n", ans[n]);
		}
	return 0;
}
