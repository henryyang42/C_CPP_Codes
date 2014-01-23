#include<stdio.h>

int main(){
	int ct = 0, t, n, s[101][101];
	while(scanf("%d%d", &n, &t) > 0, n + t){
		int i, j;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%d", &s[i][j]);
		printf("Case #%d:\n", ++ct);
		int k, a1, b1, a2, b2, tot;
		for(k = 0; k < t; k++){
			tot = 0;
			scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
			a1--, a2--, b1--, b2--;
			for(i = a1; i <= a2; i++)
				for(j = b1; j <= b2; j++)
					tot += s[i][j];
			printf("%d\n", tot);
		}	
	}
	return 0;
}
