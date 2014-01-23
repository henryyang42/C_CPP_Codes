#include<stdio.h>

int main(){
	int i, a, t, b, j, tot, s, k, l, tag = 0;
	while(scanf("%d", &t) > 0)
		while(t--){
			scanf("%d%d", &a, &b);
			while(b--){
				if(tag++)
					putchar(10);
				for(i = 1; i < a; i++, putchar(10))
					for(j = 0; j < i; j++)
						putchar('0' + i);
				for(i = a; i > 0; i--, putchar(10))
					for(j = 0; j < i; j++)
						putchar('0' + i);
				
			}
		}
	return 0;
}

