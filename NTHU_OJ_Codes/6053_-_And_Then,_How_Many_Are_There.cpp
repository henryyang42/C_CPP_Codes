#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct Disk{
	double x, y, r;
	int c, id;
}disk[30];
vector<Disk> colors[6];
char dp[1<<24];
double dis[25][25];
bool iscover(int a, int b){
	double r = (disk[a].r+disk[b].r)*(disk[a].r+disk[b].r);
	if(dis[a][b] < r){
		return true;
	}
	return false;
}
bool ontop(int a, int state){
	for(int i = 0; i < a; i++)
		if(!((state >> i) & 1) && iscover(i, a)){
			return false;
		}
	return true;
}
bool pairable(int a, int b, int state){
	if(!iscover(a, b) && ontop(a, state) && ontop(b, state))
		return true;
	return false;
}
int main(){
	int n;
	while(scanf("%d", &n), n){
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= 4; i++)
			colors[i].clear();
		for(int i = 0; i < n; i++){
			scanf("%lf%lf%lf%d", &disk[i].x, &disk[i].y, &disk[i].r, &disk[i].c);
			disk[i].id = i;
			colors[disk[i].c].push_back(disk[i]);
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				dis[i][j] = (disk[i].x-disk[j].x)*(disk[i].x-disk[j].x)+(disk[i].y-disk[j].y)*(disk[i].y-disk[j].y);
		int M = 1 << n;
		for(int i = 0; i < M; i++){
			if(i > 0 && !dp[i])
				continue;
			for(int c = 1; c <= 4; c++){
				for(int j = 0; j < colors[c].size(); j++){
					if((1<<colors[c][j].id)& i)
						continue;
						for(int k = j+1; k < colors[c].size(); k++){
							if((1<<colors[c][k].id) & i)
								continue;
							if(pairable(colors[c][j].id, colors[c][k].id, i)){
								int nstate = i | (1<<colors[c][j].id) | (1<<colors[c][k].id);
								if(dp[nstate] < dp[i] + 2)
									dp[nstate] = dp[i]+2;
							}
						}
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < M; i++)
			if(ans < dp[i])
				ans = dp[i];
		printf("%d\n", ans);
	}
	return 0;
}
