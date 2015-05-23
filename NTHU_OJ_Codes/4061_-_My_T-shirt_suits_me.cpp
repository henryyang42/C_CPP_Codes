#include<cstdio>
#include<string>
#include<map>
#include<cstring>
#include<iostream>
using namespace std;
map<string, int> M;
string sizes[] = {"XXL", "XL", "L","M", "S", "XS"}, s;
int adj[200][200], v[200], match[200], t, n, m;
bool bi(int x){
	for(int i = 0; i < n; i++)
		if(adj[x][i] && !v[i]){
			v[i] = 1;
			if(match[i] == -1 || bi(match[i])){
				match[i] = x;
				return true;
			}
		}
	return false;
}
int main(){
	for(int i = 0; i < 6; i++)
		M[sizes[i]] = i;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		memset(adj, 0, sizeof(adj));
		memset(match, -1, sizeof(match));
		int nn = n / 6, ind;
		for(int i = 0; i < m; i++)
			for(int j = 0; j < 2; j++){
				cin >> s;
				ind = M[s];
				for(int k = 0; k < nn; k++)
					adj[i][nn*ind+k] = 1;
			}
		int pa = 0;
		for(int i = 0; i < m; i++){
			memset(v, 0, sizeof(v));
			pa += bi(i);
		}
		if(pa != m)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}
