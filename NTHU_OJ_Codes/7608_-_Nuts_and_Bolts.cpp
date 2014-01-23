#include<stdio.h>
#include<string.h>
#include<vector>
#define pos(i,j) ((i-1)*w+j)
using namespace std;
vector<int> v[503];
int match[503], vis[503], n, h, w, t, p, s[513][513], ct;
int di[] = {1, 0,-1, 0};
int dj[] = {0, 1, 0,-1};
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
int main(){
	scanf("%d", &t);
	while(t--){
		memset(s, 0, sizeof(s));
		scanf("%d%d", &h, &w);
		for(int i = 1; i <= h; i++)
			for(int j = 1; j <= w; j++)
				scanf("%d", &s[i][j]);
		n = p = 0;
		for(int i = 1; i <= h; i++)
			for(int j = 1; j <= w; j++){
				//v[pos(i, j)].clear();
				if(s[i][j] && (i + j) % 2){n++;
					/*for(int k = 0; k < 4; k++){
						int _i = i + di[k], _j = j + dj[k];
						if(s[_i][_j])
							v[pos(i, j)].push_back(pos(_i, _j));
					}*/
				}
			}
		/*memset(match, 0, sizeof(match));
		for(int i = 1; i <= w*h; i++)
			if(v[i].size()){
				memset(vis, 0, sizeof(vis));
				bi(i);
			}
		for(int i = 1; i <= w*h; i++)
			p += match[i] > 0;*/
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",++ct, n);
	}
	return 0;
}
