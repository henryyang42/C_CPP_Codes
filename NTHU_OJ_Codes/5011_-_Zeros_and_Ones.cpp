#include<stdio.h>
char s[1000011];
int dp0[1000011], dp1[1000011];
int main(){
	int q, a, b, ct = 0, i;
	while(gets(s+1) > 0 && s[1]){
		scanf("%d", &q);
		printf("Case %d:\n", ++ct);
		for(i = 1; s[i] ;i++){
			dp0[i] = dp0[i-1] + (s[i] == '0');
			dp1[i] = dp1[i-1] + (s[i] == '1');
		}
		while(q--){
			scanf("%d%d", &a, &b);
			if(dp1[a] == dp1[b+1] || dp0[a] == dp0[b+1])
				puts("Yes");
			else
				puts("No");

		}
		getchar();
	}
	return 0;
}
