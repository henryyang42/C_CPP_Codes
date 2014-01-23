#include<stdio.h>
#include<stdlib.h>
int t, n, m, i, s[10000], q, ct = 0;
void ans(int q){
	int i, tot = 0;
	for(i = 0; i <= n; i++)
		tot = tot*q + s[i], tot %= 10000007;
	printf("%d\n", tot);
}
int main(){
	while(scanf("%d", &t) > 0)
		while(t--){
			printf("Case %d:\n", ++ct);
			scanf("%d", &n);
			for(i = 0; i <= n; i++)
				scanf("%d", &s[i]);
			scanf("%d", &m);
			for(i = 0; i < m; i++)
				scanf("%d", &q), ans(q);
		}
    return 0;
}
