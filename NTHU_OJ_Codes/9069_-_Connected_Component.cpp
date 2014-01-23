#include<stdio.h>
int ct[100001], g[100001];
int find_(int x){
	return x == g[x] ? x : (g[x] = find_(g[x]));
}
int main(){
	int a, b, n, m, max;
	while(scanf("%d", &n), n){
		scanf("%d", &m);
		for(int i = 0; i <= n; i++)
			g[i] = i, ct[i] = 0;
		while(m--){
			scanf("%d%d", &a, &b);
			g[find_(a)] = find_(b);
		}
		max = 0;
		for(int i = 0; i <= n; i++)
			ct[find_(i)]++;
		for(int i = 0; i <= n; i++)
			max = max > ct[i] ? max : ct[i];
		printf("%d\n", max);
	}
	return 0;
}
