#include<stdio.h>
#include<string.h>
#include<ctype.h>
char adj[128][128] = {0}, fg = 0, visit[128] = {0}, s[10000][100], start[128];
char stack[101], sz;
void dfs(int x){
	visit[x] = 1;
	int j;
    for(j = 0; j < 128; j++)
        if(adj[x][j] && visit[j] == -1)
            dfs(j);
	stack[sz++] = x;
}
int main(){
	int ct = 0, i, j;
	while(scanf("%s", s[ct]) > 0){
		if(s[ct][0] == '#'){
			memset(adj, 0, sizeof(adj));
			memset(visit, 0, sizeof(visit));
			memset(start, 0, sizeof(start));
			sz = 0;
			for(i = 0; i < ct - 1; i++){
				j = i + 1;
				if(strlen(s[i]) == strlen(s[j])){
					int k = 0, l = strlen(s[i]);
					while(k < l && s[i][k] == s[j][k])
						k++;
					if(s[i][k] != s[j][k])
						adj[s[i][k]][s[j][k]] = 1, visit[s[j][k]] = visit[s[i][k]] = -1;
				}
			}
			for(i = ct = 0; i < 128; i++)
				if(visit[i] == -1){
					dfs(i);
					//if(ct++) while(1);
				}
			for(i = 35; i >= 0; i--)
				putchar(stack[i]);
			putchar(10);
			ct = 0;
			continue;
		}
		for(i = ct + 1; i < ct + 10; i++)
			scanf("%s", s[i]);
		ct += 10;
	}
	return 0;
}
