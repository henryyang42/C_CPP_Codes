#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
vector<int> v[403];
int match[403], vis[403], s[403];
bool prime[2000003];
bool bipartite(int x){
	for(int i = 0; i < v[x].size(); i++){
		int y = v[x][i];
		if(!prime[s[x] + s[y]] && !vis[y]){
			vis[y] = 1;
			if(!match[y] || bipartite(match[y])){
				match[y] = x;
                return true;
			}
		}
	}
	return false;
}
int main(){
	int n;
	for(int i = 2; i < 2000000; i++)
		if(!prime[i])
			for(int j = i<<1; j < 2000000; j += i)
				prime[j] = 1;
	while(scanf("%d", &n) > 0){
		for(int i = 1; i <= n; i++)
			scanf("%d", &s[i]);
		for(int i = 1; i <= n; i++){
			v[i].clear();
			if(s[i] % 2){
				for(int j = 1; j <= n; j++)
					if(s[j] % 2 == 0)
						v[i].push_back(j);
			}
		}
		memset(match, 0, sizeof(match));
		for(int i = 1; i <= n; i++){
			memset(vis, 0, sizeof(vis));
			bipartite(i);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
			ans += match[i] > 0;
		printf("%d\n", ans);
	}
	return 0;
}
