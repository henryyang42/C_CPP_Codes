#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
double adj[201][201], x[201], y[201], ans;
int visit[201], n, ct = 0;
int main(){
	while(scanf("%d", &n), n){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				adj[i][j] = 0;
		for(int i = 0; i < n; i++)
			scanf("%lf%lf", &x[i], &y[i]), visit[i] = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				adj[i][j] = adj[j][i] = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", ++ct, adj[0][1]);
	}
	return 0;
}
