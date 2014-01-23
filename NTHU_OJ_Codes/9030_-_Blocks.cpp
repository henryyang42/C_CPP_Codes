#include<stdio.h>
int factor[10000], ct, ans, s[3];
void dfs(int n, int level, int k){
	if(level == 2){
		ans = ans < 2*s[0]*s[1] + 2*n*(s[0]+s[1]) ? ans : 2*s[0]*s[1] + 2*n*(s[0]+s[1]);
		return;
	}
	for(int i = k; i < ct; i++)
		if(n % factor[i] == 0)
			s[level] = factor[i], dfs(n / factor[i], level+1, i);
}
int main(){
	int t, n, i;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(ct = 0, i = 1; i <= n; i++)
			if(n % i == 0)
				factor[ct++] = i;
		ans = 100000000;
		dfs(n, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
