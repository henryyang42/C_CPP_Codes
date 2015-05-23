#include<cstdio>
int ans, n, x, y;
void dfs(int lv, int rec, int reca, int recb){
	if(lv == n){
		ans++;
		return;
	}
	for(int i = 0; i < n; i++){
		if(lv == x && i == y || lv != x)
			if(!((rec>>i)&1) && !((reca>>i)&1) && !((recb>>i)&1)){
				dfs(lv + 1, rec|(1<<i), (reca|(1<<i))>>1, (recb|(1<<i))<<1);
			}
	}
}
int main(){
	while(scanf("%d%d%d", &n, &x, &y) > 0){
		ans = 0;
		x--, y--;
		dfs(0, 0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
