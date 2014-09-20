#include<stdio.h>
#include<stdlib.h>
int main(){
	int t, n, i, j, stack[10000], now, ct = 0;char s[10000][4];
	while(scanf("%d", &t) > 0)
		while(t--){
			ct++, now = 0;
			scanf("%d", &n);
			for(i = 0; i < n; i++)
				scanf("%s", s[i]);
			for(i = 0; i < n; i++)
				if(atoi(s[i]) >= 0 && s[i][0] >= '0' && s[i][0] <= '9')
					stack[now++] = atoi(s[i]);
				else{
					now--;
					switch(s[i][0]){
						case '+':
							stack[now-1] += stack[now];
							break;
						case '-':
							stack[now-1] -= stack[now];
							break;
						case '*':
							stack[now-1] *= stack[now];
							break;
						case '/':
							stack[now-1] /= stack[now];
							break;
						case '%':
							stack[now-1] %= stack[now];
							break;
					}
				}
			printf("Case %d: %d\n", ct, stack[0]);
		}
    return 0;
}
