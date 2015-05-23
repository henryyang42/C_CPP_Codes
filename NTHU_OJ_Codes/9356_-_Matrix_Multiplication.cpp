#include<cstdio>

int main(){
	int t, m, n, p;
	scanf("%d", &t);
	while(t--){
		long long ans[101][101] = {}, s[101][101], t[101][101];
		scanf("%d%d%d", &m, &n, &p);
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				scanf("%lld", &s[i][j]);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < p; j++)
				scanf("%lld", &t[i][j]);
		for(int i = 0; i < m; i++)
			for(int j = 0; j < p; j++)
				for(int k = 0; k < n; k++)
					ans[i][j] += s[i][k] * t[k][j];
		for(int i = 0; i < m; i++, putchar(10))
			for(int j = 0; j < p; j++){
				if(j)
					putchar(32);
				printf("%lld", ans[i][j]);
			}
		putchar(10);
	}
	return 0;
}
