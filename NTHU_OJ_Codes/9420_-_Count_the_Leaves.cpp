#include <cstdio>

int main(){
	int n, a, b;
	while(scanf("%d", &n), n){
		int in[1001] = {}, rec[1001] = {}, ans = 0;
		for(int i = 0; i < n; i++){
			scanf("%d%d", &a, &b);
			rec[a] = rec[b] = 1;
			in[a]++;
		}
		scanf("%d", &b);
		for(int i = 0; i <= 1000; i++)
			if(rec[i] && !in[i])
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}
