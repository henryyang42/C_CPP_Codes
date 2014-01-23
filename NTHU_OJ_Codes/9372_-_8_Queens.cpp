#include <cstdio>
int data[200][9], ct, temp[9];
void dfs(int lv, int c, int l, int r){
	if(lv == 8){
		for(int i = 0; i < 8; i++)
			data[ct][i] = temp[i];
		ct++;
		return;
	}
	for(int i = 0; i < 8; i++)
		if(!((c >> i)&1)&&!((r >> i)&1)&&!((l >> i)&1)){
			temp[lv] = i;
			dfs(lv + 1, c|(1 << i), (l|(1 << i))>>1, (r|(1 << i))<<1);
		}
}
int main(){
	dfs(0, 0, 0, 0);
    int t;
    scanf("%d", &t);
    while(t--){
    	int ans = 0, s[9][9];
    	for(int i = 0; i < 8; i++)
    		for(int j = 0; j < 8; j++)
    			scanf("%d", &s[i][j]);
		for(int i = 0; i < ct; i++){
			int tot = 0;
			for(int j = 0; j < 8; j++)
				tot += s[j][data[i][j]];
			ans = tot > ans ? tot : ans;
		}
		printf("%5d\n", ans);
    }
    return 0;
}
