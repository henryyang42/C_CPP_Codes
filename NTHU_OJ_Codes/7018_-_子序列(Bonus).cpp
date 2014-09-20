#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[16], temp[16], ans[1000000][16], visit[16];
int l, k, ansct;
void dfs(int from, int dep){
	if(dep == k){
		temp[dep] = 0;
		memcpy(ans[ansct++], temp, sizeof(temp));
		return;
	}
	int i;
	for(i = from; i < l; i++)
		if(!visit[i]){
			temp[dep] = s[i];
			visit[i] = 1;
			dfs(i + 1, dep + 1);
			visit[i] = 0;
		}
}
int compare(const void *v, const void *o){
	return strcmp((char*)v, (char*)o);
}
int main(){
	int t, fg = 0, i;
	scanf("%d", &t);
	while(t--){
		scanf("%s%d", s, &k);
		l = strlen(s);
		ansct = 0;
		memset(visit, 0, sizeof(visit));
		dfs(0, 0);
		printf("Case #%d:\n", ++fg);
		qsort(ans, ansct, sizeof(ans[0]), compare);
		for(i = 0; i < ansct; i++)
			puts(ans[i]);
	}
	return 0;
}
