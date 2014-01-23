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
			scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
			a1--, a2--, b1--, b2--;
			if(a1 > a2)
				tot = a1, a1 = a2, a2 = tot;
			if(b1 > b2)
				tot = b1, b1 = b2, b2 = tot;
			tot = 0;
			for(i = a1; i <= a2; i++)
				for(j = b1; j <= b2; j++)
					if(a1 <= i && i <= a2 && b1 <= j && j <= b2)
						tot += s[i][j];
			printf("%d\n", tot);
		}	
	}
	return 0;
}
