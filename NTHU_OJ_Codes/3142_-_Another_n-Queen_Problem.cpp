#include<cstdio>
int n, ct, ris[20];
char s[20];
long long ans;
void dfs(int lv, int x, int ry, int ly){
	if(lv == n){
		ans++;
		return;
	}
	int mask = x | ry | ly | ris[lv];
	for(int i = 0; i < n; i++)
		if(!((1<<i)&mask)){
			dfs(lv+1, (x|(1<<i)), (ry|(1<<i))>>1, (ly|(1<<i))<<1);
		}
}
int main(){
	while(scanf("%d", &n), n){
		for(int i = 0; i < n; i++){
			ris[i] = 0;
			scanf("%s", s);
			for(int j = 0; j < n; j++)
				if(s[j] == '*')
					ris[i] |= 1<<j;
		}
		ans = 0;
		dfs(0, 0, 0, 0);
		printf("Case %d: %lld\n", ++ct, ans);
	}
	return 0;
}
