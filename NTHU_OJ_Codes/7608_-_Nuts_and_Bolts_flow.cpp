#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int v[1003][1003];
int pre[1003], bolts, nuts, t, ct, st, ed, stop, fg;
void dfs(int x){
	for(int i = 0; i <= ed && stop; i++)
		if(v[x][i] && pre[i] == -1){
			pre[i] = x;
			if(i == ed)
				stop = 0;
			else
				dfs(i);
		}
}

int flow(){
	int ans = 0;
	while(1){
		memset(pre, -1, sizeof(pre));
		stop = 1;
		dfs(st);
		if(stop)
			return ans;
		ans++;
		for(int i = ed; i != st; i = pre[i])
			v[i][pre[i]]++, v[pre[i]][i]--;
	}
}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &bolts, &nuts);
		st = 0, ed = bolts+nuts+1;
		memset(v, 0, sizeof(v));
		for(int i = 1; i <= bolts; i++)
			v[0][i] = 1;
		for(int i = bolts+1; i <= bolts+nuts; i++)
			v[i][ed] = 1;
		for(int i = 1; i <= bolts; i++){
			for(int j = 1; j <= nuts; j++){
				scanf("%d", &fg);
				if(fg)
					v[i][j+bolts] = 1;
			}
		}
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",++ct, flow());
	}
	return 0;
}
