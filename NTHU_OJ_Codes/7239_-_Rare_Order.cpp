#include<stdio.h>
#include<string.h>
#include<ctype.h>
char adj[101][101] = {0}, start[101] = {0}, fg, visit[101] = {0}, s[10000][100];
int n = 0;
int stack[101], sz;
void dfs(int x){
	visit[x] = 1;
	int j;
    for(j = 0; j < 26; j++)
        if(adj[x][j] && visit[j] == -1)
            dfs(j);
	stack[sz++] = x;
}
int main(){
	while(scanf("%s", s[n++]) > 0, s[n - 1][0] != '#');
	n--;
	int i, j, k;
	for(i = 0; i < n - 1; i++){
		k = 0, j = i + 1;
		while(s[i][k] == s[j][k]) k++;
		if(isalpha(s[i][k]) && isalpha(s[j][k]))
			adj[s[i][k] - 'A'][s[j][k] - 'A'] = 1, visit[s[i][k] - 'A'] = visit[s[j][k] - 'A'] = -1;
	}
	for(i = 0, fg = 0, sz = 0; i <= 26; i++)
		if(visit[i] == -1)
			dfs(i);
		while(--sz >= 0)
			putchar(stack[sz] + 'A');
		putchar(10);
	return 0;
}
