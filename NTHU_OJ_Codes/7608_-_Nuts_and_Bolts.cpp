#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int> v[503];
int match[503], vis[503], ans, fg, bolts, nuts, t, ct;
bool bi(int x){
	for(int i = 0; i < v[x].size(); i++){
		int y = v[x][i];
		if(!vis[y]){
			vis[y] = 1;
			if(match[y] == 0 || bi(match[y])){
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &bolts, &nuts);
		for(int i = 1; i <= bolts; i++){
			v[i].clear();
			for(int j = 1; j <= nuts; j++){
				scanf("%d", &fg);
				if(fg)
					v[i].push_back(j);
			}
		}
		memset(match, 0, sizeof(match));
		ans = 0;
		for(int i = 1; i <= bolts; i++){
			memset(vis, 0, sizeof(vis));
			if(bi(i))
				ans++;
		}
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",++ct, ans);
	}
	return 0;
}
