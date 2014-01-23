#include<map>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int n, a, b, ct, t, visit[10001], low[10001], m;
vector<int> l[10001], S;
map<pair<int, int>, int> M, bct;
void dfs(int now, int pre){
	low[now] = visit[now] = ++t;
	int child = 0, bridge = 0;
	for(int i = 0; i < l[now].size(); i++){
		int x = l[now][i];
		if(x != pre){
			if(visit[x]){
				low[now] = min(low[now], visit[x]);
			}
			else{
				child++;
				dfs(x, now);
				low[now] = min(low[now], low[x]);
				if(low[x] > visit[now] && bct[make_pair(x, now)] == 1){
					ct++, S.push_back(M[make_pair(x, now)]);
				}
			}
		}
	}
}
int main(){
	int casect;
	scanf("%d", &casect);
	while(casect--){
		scanf("%d%d", &n, &m);
		S.clear();
		bct.clear();
		ct = t = 0;
		for(int i = 1; i <= n; i++)
			l[i].clear(), visit[i] = low[i] = 0;
		for(int id = 1; id <= m; id++){
			scanf("%d%d", &a, &b);
			if(M[make_pair(a, b)] == 0){
				M[make_pair(a, b)] = id;
				bct[make_pair(a, b)] = 1;
				l[a].push_back(b);
			}
			else{
				bct[make_pair(a, b)]++;
			}
			if(M[make_pair(b, a)] == 0){
				M[make_pair(b, a)] = id;
				bct[make_pair(b, a)] = 1;
				l[b].push_back(a);
			}
			else{
				bct[make_pair(b, a)]++;
			}
		}
		for(int i = 1; i <= n; i++)
			if(!visit[i])
				dfs(i, i);
		printf("%d\n", ct);
		sort(S.begin(), S.end());
		for(int i = 0; i < S.size(); i++){
			if(i)
				putchar(32);
			printf("%d", S[i]);
		}
		if(S.size())
			putchar(10);
		if(casect)
			puts("");
	}
	return 0;
}

