#include<stdio.h>
#include<stdlib.h>
int s[11], ct[11], temp[11], t, i, n, m, casect = 0;
void dfs(int level, int m){
	int i;
	if(m == level){
		for(i = 0; i < m; i++)
			putchar(temp[i] + '0');
		putchar(10);
		return;
	}
	for(i = 0; i < n; i++)
		if(ct[i] == 0){
			temp[level] = s[i];
			ct[i] = 1;
			dfs(level + 1, m);
			ct[i] = 0;	
		}	
}
int com(const void *v, const void *o){
	return *(int*) v - *(int*) o;
}
int main(){
	while(scanf("%d", &t) > 0)
		while(t--){
			casect++;
			scanf("%d%d", &n, &m);
			for(i = 0; i < n; i++)
				scanf("%d", &s[i]);
			qsort(s, n, sizeof(int), com);
			printf("Case %d:\n", casect);
			dfs(0, m);
		}
    return 0;
}
