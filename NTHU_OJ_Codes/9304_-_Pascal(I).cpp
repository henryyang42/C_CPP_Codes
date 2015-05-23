#include<stdio.h>
int ans[1021][1021] = {0}, i, j, n;
int main(){
	ans[0][0] = 1;
	ans[1][0] = 1, ans[1][1] = 1;
	for(i = 2; i < 1001; i++)
		for(j = 0; j <= i; j++)
			ans[i][j] = (ans[i-1][j] + ans[i-1][j-1]) % 1000007;
	while(scanf("%d", &n) > 0){
		for(i = 0; i <= n; i++){
			if(i)
				putchar(32);
			printf("%d", ans[n][i]);
		}
		putchar(10);	
	}
	return 0;
}
