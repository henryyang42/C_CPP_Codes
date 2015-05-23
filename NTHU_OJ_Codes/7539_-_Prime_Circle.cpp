#include<stdio.h>
#include<stdlib.h>
#include<string.h>
          /*  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32}*/
int prime[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0};
int ans[17] = {0};
int ct[100], n, rec[100];
void dfs(int level){
    int i;
    if(n % 2){
        return;
    }
    if(level == n){
        ans[n] += prime[1 + rec[n - 1]];
        return;
    }
    for(i = 2; i <= n; i++)
        if(!ct[i] && prime[i + rec[level - 1]])
            ct[i] = 1, rec[level] = i, dfs(level+1), ct[i] = 0;
}
int main(){
	for(n = 1; n < 17; n++){
		memset(ct, 0, sizeof(ct));
		rec[0] = 1;
		ct[1] = 1;
		dfs(1);
	}
    while(scanf("%d", &n) > 0){
        printf("%d\n", ans[n]);
    }
    return 0;
}
