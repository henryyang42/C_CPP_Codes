#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char s[1000];
int main(){
	while(gets(s) > 0){
		int adj[51][51] = {0}, n = 1, t, fg = 0;
		int stack[51], now = 0, i ,j , ct[51] = {0};
		for(i = 0; s[i]; i++){
			if(s[i] == '(')
				now++;
			if(s[i] == ')')
				now--;
			if(isdigit(s[i])){
				char temp[3] = {0};
				int j = 0;
				while(isdigit(s[i]))
					temp[j++] = s[i++];
					stack[now] = atoi(temp);
					if(n < stack[now])
						n = stack[now];
					if(now > 1){
						adj[stack[now]][stack[now - 1]] = adj[stack[now - 1]][stack[now]] = 1;
						ct[stack[now]]++;
						ct[stack[now - 1]]++;
					}
					i--;
			}
		}
		t = n - 1;
		while(t--){
			if(fg++)
				putchar(32);
			for(i = 1; i <= n; i++)
				if(ct[i] == 1){
					for(j = 1; j <= n; j++)
						if(adj[i][j] && ct[j])
							break;
					printf("%d",j);
					ct[i]--, ct[j]--;
					adj[i][j] = adj[j][i] = 0;
					break;
				}
		}
		putchar(10);
	}
	return 0;
}
