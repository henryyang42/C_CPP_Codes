#include<iostream>
#include<sstream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n, a, b, ct, t, visit[101], low[101], adj[101][101];
void dfs(int now, int pre){
	low[now] = visit[now] = ++t;
	int child = 0, ap = 0;
	for(int i = 1; i <= n; i++)
		if(adj[now][i] && i != pre){
			if(visit[i]){
				low[now] = min(low[now], visit[i]);
			}
			else{
				child++;
				dfs(i, now);
				low[now] = min(low[now], low[i]);
				if(low[i] >= visit[now])
					ap = 1;
			}
		}
		if(pre == now && child > 1 || pre != now && ap)
			ct++;
}
int main(){
	while(cin >> n, n){
		ct = t = 0;
		memset(visit, 0, sizeof(visit));
		memset(adj, 0, sizeof(adj));
		string s;
		while(getline(cin, s)){
			if(s == "0")
				break;
			stringstream ss;
			ss << s;
			ss >> a;
			while(ss >> b)
				adj[a][b] = adj[b][a] = 1;
		}
		for(int i = 1; i <= n; i++)
			if(!visit[i])
				dfs(i, i);
		cout << ct << "\n";
	}
	return 0;
}
