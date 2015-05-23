#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct Node{
	int con, to, dis;
}E;
int adj[100][100], cond[100][100];
vector<Node> node[100];
int t, n, m, k, p;
int SPFA(int st, int ed){
	queue<int> q;
	int dis[100], visit[100];
	for(int i = 0; i <= n; i++)
		dis[i] = 1e9, visit[i] = 0;
	dis[st] = 0;
	q.push(st);
	q.push(-1);
	while(!q.empty()){
		int from = q.front();q.pop();
		int f_con = q.front();q.pop();
		visit[from] = 0;
		/*for(int i = 0; i < node[from].size(); i++){
			int to = node[from][i].to;
			for(int j = 0; j < node[to].size(); j++){
				int t_con = node[to][j].con;
				if(t_con != f_con && dis[to] > dis[from] + adj[from][to]){
					dis[to] = dis[from] + adj[from][to];
					if(!visit[to]){
						q.push(to), visit[to] = 1;
						q.push(t_con);
					}
				}
			}
		}*/
		for(int i = 0; i <= n; i++)
			if(adj[from][i] && f_con != cond[from][i] && dis[i] > dis[from] + adj[from][i]){
				dis[i] = dis[from] + adj[from][i];
				if(!visit[i]){
					visit[i] = 1;
					q.push(i);
					q.push(cond[from][i]);
				}
			}
	}
	return dis[ed];
}
int ans, vi[100];
void dfs(int x, int len,int con, int st){
	vi[x] = 1;
	if(len > ans)
		return;
	if(x == st){
		if(ans > len)
			ans = len;
		return;
	}
	for(int i = 0; i <= n; i++)
		if(adj[x][i] && con != cond[x][i] && !vi[i]){
			vi[i] = 1;
			dfs(i, len + adj[x][i], cond[x][i], st);
			vi[i] = 0;
		}
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d", &n, &m, &k, &p);
        for(int i = 0; i <= n; i++){
			node[i].clear();
        	for(int j = 0; j <=n ;j++)
				adj[i][j] = 0;
        }
        while(m--){
            int a, b, l, c;
            scanf("%d%d%d%d", &a, &b, &l, &c);
            E.con = c;
            E.to = b;
            E.dis = l;
            node[a].push_back(E);
            E.to = a;
            node[b].push_back(E);
            adj[a][b] = adj[b][a] = l;
            cond[a][b] = cond[b][a] = c;
        }
        while(p--){
			for(int i = 0; i <= n; i++) vi[i] = 0;
            int a, b;
            ans = 1e9;
            scanf("%d%d", &a, &b);
            dfs(a, 0, 0, b);
            if(ans != 1e9)
                printf("%d\n", ans);
            else
                puts("infinity");


        }
    }
    return 0;
}
