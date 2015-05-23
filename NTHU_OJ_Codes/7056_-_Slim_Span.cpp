#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, ans, g[10001];
struct edge{
	int a, b, w;
	bool operator < (const edge &x) const{
		return x.w > w;
	}
}E;
int find_(int x){
	return x == g[x] ? x : (g[x] = find_(g[x]));
}
vector<edge> v;
void calc(){
	for(int i = 0; i < m; i++){
		for(int j = 0; j <= n; j++)
			g[j] = j;
		int ct = 0;
		for(int j = i; j < v.size(); j++){
			int fa = find_(v[j].a), fb = find_(v[j].b);
			if(fa != fb){
				ct++;
				g[fa] = fb;
			}
			if(ct == n - 1){
				ans = min(ans, v[j].w - v[i].w);
				break;
			}
		}
	}
}
int main(){
	while(scanf("%d%d", &n, &m) > 0, n + m){
		v.clear();
		for(int i = 0; i < m; i++){
			scanf("%d%d%d", &E.a, &E.b, &E.w);
			v.push_back(E);
		}
		ans = 1e9;
		sort(v.begin(), v.end());
		calc();
		if(ans == 1e9)
			puts("-1");
		else
			printf("%d\n", ans);
	}
	return 0;
}
