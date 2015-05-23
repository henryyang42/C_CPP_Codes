#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int, double> > l[1000];
long long dis[1000];
double adj[1000][1000], c;
int main(){
	int n, m, a, b, ct = 0;
	while(scanf("%d%d", &n, &m), n + m){
		memset(adj, 0, sizeof(adj));
		for(int i = 0; i <= n; i++)
			l[i].clear(), dis[i] = 1e10;
		for(int i = 0; i < m; i++){
			scanf("%d%d%lf", &a, &b, &c);
			l[a].push_back(make_pair(b, c));
			l[b].push_back(make_pair(a, c));
			adj[a][b] = adj[b][a] = c;
		}
		queue<int> q;
		int in[1000] = {};
		q.push(1);
		dis[1] = 0;
		while(!q.empty()){
			int x = q.front(); q.pop();
			in[x] = 0;
			for(int i = 0; i < l[x].size(); i++){
				int next = l[x][i].first;
				double len = l[x][i].second;
				if(dis[x] + len < dis[next]){
					dis[next] = dis[x] + len;
					if(!in[next])
						in[next] = 1, q.push(next);
				}
			}
		}
		/*double Max = 0;
		int inda = 0, indb = 0;
		for(int i = 1; i <= n; i++)
			if(dis[i] > Max)
				Max = dis[i], inda = i;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)if(adj[i][j]){
				double time;
				if(dis[i] > dis[j])
					time = (adj[i][j] - (dis[i]-dis[j]))/2.0;
				else
					time = (adj[i][j] - (dis[j]-dis[i]))/2.0;
				if(time +1e-8> Max)
					Max = time, inda = i, indb = j;
			}
		}
		printf("System #%d\n", ++ct);
		if(indb)
			printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n", Max, min(inda, indb), max(inda, indb));
		else
			printf("The last domino falls after %.1lf seconds, at key domino %d.\n\n", Max, inda);
		*/
		double single = 0, two = -1;
        int sret = 1, tret1 = 1, tret2 = 1;
        for(int i = 1; i <= n; i++) {
            if(dis[i] > single) {
                single = dis[i];
                sret = i;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(vector<pair<int, double> >::iterator it = l[i].begin();
                it != l[i].end(); it++) {
                if(dis[i] > dis[it->first]) {
                    double time = (it->second - (dis[i]-dis[it->first]))/2.0;
                    if(time + dis[i] > two) {
                        two = time + dis[i];
                        tret1 = i, tret2 = it->first;
                    }
                } else {
                    double time = (it->second - (dis[it->first]-dis[i]))/2.0;
                    if(time + dis[it->first] > two) {
                        two = time + dis[it->first];
                        tret1 = i, tret2 = it->first;
                    }
                }
            }
        }
        if(tret1 > tret2)   swap(tret1, tret2);
        printf("System #%d\n", ++ct);
        if(single+1e-8 > two) {
            printf("The last domino falls after %.1lf seconds, at key domino %d.\n", single, sret);
        } else {
            printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n", two, tret1, tret2);
        }
        putchar(10);
	}
	return 0;
}

