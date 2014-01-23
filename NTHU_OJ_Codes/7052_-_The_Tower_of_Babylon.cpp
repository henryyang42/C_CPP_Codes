#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int adj[200][200], c[200][3];
int dd[6][2] = {{0, 1}, {0, 2}, {1, 0}, {2, 0}, {1, 2}, {2, 1}};
int d[] = {2, 1, 2, 1, 0, 0};
int h(int i, int k, int j, int l){
	if(c[i][dd[k][0]] < c[j][dd[l][0]] && c[i][dd[k][1]] < c[j][dd[l][1]]){
		return c[i][d[k]];
	}
	return -1e9;
}
int main(){
	int t, n, Max, ct= 0;
	while(scanf("%d", &n) > 0, n){
		for(int i = 0; i < 200; i++)
			for(int j = 0; j < 200; j++)
				adj[i][j] = -1e9;
		for(int i = 0; i < n; i++)
			scanf("%d%d%d", &c[i][0], &c[i][1], &c[i][2]);
		c[n][0] = c[n][1] = c[n++][2] = 1e9;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				for(int k =0 ; k < 6; k++)
					for(int l = 0; l < 6; l++){
						adj[i*6+k][j*6+l] = h(i, k, j, l);
					}
			}
		Max = 0;
		for(int k = 0; k < n*6; k++)
			for(int i = 0; i < n*6; i++)
				for(int j = 0; j < n*6; j++){
					adj[i][j] = max(adj[i][j], adj[i][k] + adj[k][j]);
					Max = max(Max, adj[i][j]);
				}
		printf("Case %d: maximum height = %d\n",++ct, Max);
	}
	return 0;
}
