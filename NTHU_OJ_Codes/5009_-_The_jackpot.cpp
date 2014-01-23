#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int i, j, k, l, s[10001], a;
	while(scanf("%d",&a)>0, a){
		int dp[10001] = {0}, tot = 0, ans = -2147483647;
		for(i = 0; i < a; i++)
			scanf("%d",&s[i]);
		for(i = 0; i < a; i++)
			dp[i] = tot,tot += s[i] ;
		dp[a] = tot;
		for(i = 0; i < a; i++)
			for(j = i; j <= a; j++)
				if(dp[j] - dp[i] > ans)
					ans = dp[j] - dp[i];
		if(ans > 0)
			printf("The maximum winning streak is %d.\n",ans);
		else
			puts("Losing streak.");
	}	
	return 0;
}
