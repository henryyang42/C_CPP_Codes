#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int n, m, fg = 0;
struct edge{
	int a, b;
	double num;
	int N;
}e[10001];
int g[10001];
int compare(const void *v, const void *o){
	return (((edge*)v) -> N) - (((edge*)o) -> N);
}
int find(int x){
	while(x != g[x])
		x = g[x];
	return x;
}
int main(){
	while(scanf("%d%d", &n, &m) > 0){
		int i, v = n - 1;;
		double ans = 0;
		for(i = 0; i < m; i++)
			scanf("%d%d%lf", &e[i].a, &e[i].b, &e[i].num), e[i].N = e[i].num;
		for(i = 1; i <= n; i++)
			g[i] = i;
		qsort(e, m, sizeof(edge), compare);
		i = 0;
		while(v--){
			while(1){
				int fa = find(e[i].a), fb = find(e[i].b);
				i++;
				if(fa != fb){
					g[fa] = fb;
					ans += log(e[i - 1].num);
					break;
				}
			}
		}
		printf("Case %d: %.2lf\n", ++fg, ans);
	}
	return 0;
}
