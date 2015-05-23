#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#define U 0
#define D 1
#define L 2
#define R 3
#define MAX 1e9
int dx[] = {1,-1, 0, 0};
int dy[] = {0, 0,-1,1};
using namespace std;
int adj[301][301][4];
int dis[50001], in[50001] = {};
int SPFA(int edx, int edy){
	if(edx < 0 || edy < 0 || edx > 200 || edy > 200)
		return 0;
	for(int i = 0; i < 50000; i++)
		dis[i] = MAX, in[i] = 0;
	queue<int> q;
	q.push(0);
	dis[0] = 0;
	while(!q.empty()){
		int x = q.front() / 200, y = q.front() % 200;
		q.pop();
		in[200*x+y] = 0;
		for(int k = 0; k < 4; k++)
			if(adj[x][y][k] != MAX){
				int x_ = x + dx[k], y_ = y + dy[k];
				if(x_ >= 0 && + y_ >= 0 && x_ <= 200 && y_ <=200 && dis[x_*200+y_] > dis[x*200+y] + adj[x][y][k]){
					dis[x_*200+y_] = dis[x*200+y] + adj[x][y][k];
					if(!in[200*x_+y_])
						q.push(200*x_+y_), in[200*x_+y_] = 1;
				}
			}
	}
	return dis[200*edx + edy];
}
int main(){
	int w, d, x, y, dir, l;
	while(scanf("%d%d", &w, &d), w + d != -2){
		memset(adj, 0, sizeof(adj));
		while(w--){
			scanf("%d%d%d%d", &x, &y, &dir, &l);
			if(dir){ //parallel to y
				for(int k = y; k < y + l; k++)
					adj[x][k][D] = MAX, adj[x-1][k][U] = MAX;
			}
			else{
				for(int k = x; k < x + l; k++)
					adj[k][y][L] = MAX, adj[k][y-1][R] = MAX;
			}
		}
		while(d--){
			scanf("%d%d%d", &x, &y, &dir);
			if(dir){ //parallel to y
				adj[x][y][D] = 1, adj[x-1][y][U] = 1;
			}
			else{
				adj[x][y][L] = 1, adj[x][y-1][R] = 1;
			}
		}
		double Edx,  Edy;
		scanf("%lf%lf", &Edx, &Edy);
		int edx = Edx, edy = Edy;
		int ans = SPFA(edx, edy);
		printf("%d\n", ans == MAX ? -1 : ans);
	}
	return 0;
}
