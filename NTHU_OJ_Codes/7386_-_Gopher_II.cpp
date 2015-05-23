#include<stdio.h>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;
vector<int> v[103];
pair<double, double> gopher[103], hole[103];
int match[103], vis[103];
bool bi(int x){
	for(int i = 0; i < v[x].size(); i++){
		int y = v[x][i];
		if(!vis[y]){
			vis[y] = 1;
			if(!match[y] || bi(match[y])){
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}
double dis(double x, double y, double _x, double _y){
	return sqrt((x-_x)*(x-_x) + (y-_y)*(y-_y));
}
int main(){
	int n, m, vo, s, p;
	double x, y;
	while(scanf("%d%d%d%d", &n, &m, &s, &vo) > 0){
		for(int i = 1; i <= n; i++){
			scanf("%lf%lf", &x, &y);
			gopher[i] = make_pair(x, y);
		}
		for(int i = 1; i <= m; i++){
			scanf("%lf%lf", &x, &y);
			hole[i]= make_pair(x, y);
		}
		for(int i = 1; i <= n; i++){
			double x = gopher[i].first, y = gopher[i].second;
			v[i].clear();
			for(int j = 1; j <= m; j++){
				double _x = hole[j].first, _y = hole[j].second;
				if(dis(x, y, _x, _y) <= s*vo)
					v[i].push_back(j);
			}
		}
		memset(match, 0, sizeof(match));
		for(int i = 1; i <= n; i++)
			if(v[i].size()){
				memset(vis, 0, sizeof(vis));
				bi(i);
			}
		p = 0;
		for(int i = 1; i <= m; i++)
			p += match[i] > 0;
		printf("%d\n", n- p);
	}
	return 0;
}
