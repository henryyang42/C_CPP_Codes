#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;
int adj[200][200];
int main(){
	int n, q, ct = 0;
	while(scanf("%d%d", &n, &q) > 0, n+q){
		int id = 0;
		map<string, int> m;
		string s, t;
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= n; j++)
				adj[i][j] = -1e9;
		while(q--){
			int d;
			cin >> s >> t >> d;
			if(m.find(s) == m.end())
				m[s] = id++;
			if(m.find(t) == m.end())
				m[t] = id++;
			adj[m[t]][m[s]] = adj[m[s]][m[t]] = d;
		}
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					adj[i][j] = max(adj[i][j], min(adj[i][k], adj[k][j]));
		cin >> s >> t;
		printf("Scenario #%d\n", ++ct);
		printf("%d tons\n\n", adj[m[t]][m[s]]);
	}
	return 0;
}
