#include<stdio.h>
#include<string.h>
int n, q, r, x, min, end;
char adj[30][30], s[2], t[2], ans[300], temp[300], visit[30];
void find_path(int now, int len, int cost, char temp[300]){
	int i;
	temp[len] = now + 'A';
	if(now == end && cost < min){
		min = cost;
		temp[len + 1] = 0;
		strcpy(ans, temp);
		return;
	}
	for(i = 0; i < 26; i++)
		if(adj[now][i] && !visit[i]){
			visit[i] = 1;
			find_path(i, len + 1, cost + adj[now][i], temp);
			visit[i] = 0;
		}
}
int main(){
	while(scanf("%d%d", &n, &r) > 0){
			memset(visit, 0, sizeof(visit));
			memset(adj, 0, sizeof(adj));
		while(r--)
			scanf("%s%s%d", s, t, &x), adj[s[0] - 'A'][t[0] - 'A'] = adj[t[0] - 'A'][s[0] - 'A'] = x;
		scanf("%d", &q);
		while(q--){
			min = 2147483647;
			scanf("%s%s", s, t);
			end = t[0] - 'A';
			find_path(s[0] - 'A',0 ,0, temp);
			//printf("%d\n", min);
			for(x = 0; ans[x] != 0; x++){
				if(x)
					putchar(32);
				putchar(ans[x]);
			}
			putchar(10);
		}
	}
	return 0;
}
