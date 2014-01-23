#include<stdio.h>

int main(){
	int t, c = 0;
	while(scanf("%d", &t) > 0)
		while(t--){
			int i, a, b, tot = 0;
			scanf("%d%d", &a, &b);
			for(i = a; i <= b; i++)
				if(i % 2)
					tot += i;
			printf("Case %d: %d\n", ++c, tot);
		}
	return 0;
}
