#include<stdio.h>
char p[1000001];
int prime[1000001], pct, s[10001], dp[10001];
int find_(int n){
	int i;
	for(i = 1, dp[0] = s[0]; i < n; i++)
		dp[i] = dp[i - 1] + s[i];
	for(int len = 2; len <= n; len++)
		for(int from = 0; from + len <= n; from ++)
			if(!p[dp[from + len - 1] - dp[from] + s[from]]){
				printf("Shortest primed subsequence is length %d:", len);
				for(int pos = from; pos < from + len; pos++)
					printf(" %d", s[pos]);
				putchar(10);
				return 0;
			}
	return 1;
}
int main(){
	for(int i = 2; i < 1000000; i++)
		if(p[i] == 0){
			prime[pct++] = i;
			for(int j = i * 2; j < 1000000; j += i)
				p[j] = 1;
		}
	int t, n, fg;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		if(find_(n))
			puts("This sequence is anti-primed.");
	}
	return 0;
}
