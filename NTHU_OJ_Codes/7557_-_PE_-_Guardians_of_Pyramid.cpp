#include<stdio.h>
#include<string.h>
int n, r, gun[11], zombie[11], speed[11], s, valid, dead[11];
void dfs(int dep){
	if(valid)
		return;
	if(dep == r){
		int tot = 0, i;
		for(i = 0; i < n; i++)
			if(!dead[i])
				tot += speed[i];
		if(tot <= s)
			valid = 1;
		return;
	}
	int i;
	for(i = 0; i < n; i++)
		if(!dead[i] && zombie[i] <= gun[dep])
			dead[i] = 1, dfs(dep + 1), dead[i] = 0;
	dfs(dep + 1);
}
int main(){
	int i;
	while(scanf("%d%d%d", &n, &r, &s) > 0){
		memset(dead, 0, sizeof(dead));
		for(i = 0; i < n; i++)
			scanf("%d", &zombie[i]);
		for(i = 0; i < n; i++)
			scanf("%d", &speed[i]);
		for(i = 0; i < r; i++)
			scanf("%d", &gun[i]);
		valid = 0;
		dfs(0);
		if(valid)
			puts("Piece of cake!");
		else
			puts("GG! Failed again QAQ!!!");
	}
	return 0;
}
