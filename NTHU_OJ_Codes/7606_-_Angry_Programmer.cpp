#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int m, w, v[200][200], pre[200], stop, st, ed;
void dfs(int x){
	for(int i = 1; i <= m+m && stop; i++)
		if(v[x][i] && !pre[i]){
			pre[i] = x;
			if(i == m)
				stop = 0;
			else
				dfs(i);
		}
}
int flow(){
	int ans = 0;
	while(1){
		stop = 1;
		st = 1+m, ed = m;
		memset(pre, 0, sizeof(pre));
		dfs(1+m);
		if(stop)
			return ans;
		int mini = 1e9;
		for(int i = ed; i != st; i = pre[i])
			mini = min(mini, v[pre[i]][i]);
		ans += mini;
		for(int i = ed; i != st; i = pre[i])
			v[pre[i]][i] -= mini, v[i][pre[i]] += mini;
	}
}
int main(){
	while(scanf("%d%d", &m, &w), m+w){
		int x, y, c;
		memset(v, 0, sizeof(v));
		for(int i = 0; i < m-2; i++)
			scanf("%d%d", &x, &c), v[x][x+m] = c;
		while(w--){
			scanf("%d%d%d", &x, &y, &c);
			v[x+m][y] = v[y+m][x] = c;
		}
		printf("%d\n", flow());
	}
	return 0;
}
