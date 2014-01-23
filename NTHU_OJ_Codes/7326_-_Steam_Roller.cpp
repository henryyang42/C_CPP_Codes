#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
int n, m, sti, stj, edi, edj, x, ct = 0;
int dis[20001][5][2], in[20001][5][2];
vector<int> l[20001], d[20001];
int get_dir(int from, int to){
	if((from - to) == -1)
		return RIGHT;
	if((from - to) == 1)
		return LEFT;
	if((from - to) == -m)
		return DOWN;
	if((from - to) == m)
		return UP;
}

int get_len(int to ,int dir){
	int from;
	switch(dir){
		case RIGHT:
		from = to -1;
		break;
		case LEFT:
		from = to +1;
		break;
		case DOWN:
		from = to -m;
		break;
		case UP:
		from = to +m;
		break;
	}
	for(int i = 0; i < l[from].size(); i++)
		if(l[from][i] == to)
			return d[from][i];
}
int SPFA(int st, int ed){
	queue<int> q;
	for(int i = 0; i <= 20000; i++)
		for(int j = 0; j < 5; j++)
		dis[i][j][0] = dis[i][j][1] = 1e9, in[i][j][0] = in[i][j][1] = 0;
	dis[st][0][1] = 0;
	q.push(st);
	q.push(0);
	q.push(1);
	while(!q.empty()){
		int from = q.front();q.pop();
		int dir_pre = q.front();q.pop();
		int state = q.front();q.pop();
		in[from][dir_pre][state] = 0;
		for(int i = 0; i < l[from].size(); i++){
			int to = l[from][i], len = d[from][i], nstate = 0;
			int dir_now = get_dir(from, to);
			if(dir_pre == 0)
				nstate = 1, len *= 2;
			if(dir_pre == dir_now || dir_pre == 0){
				if(dis[to][dir_now][nstate] > dis[from][dir_pre][state] + len){
					dis[to][dir_now][nstate] = dis[from][dir_pre][state] + len;
					if(in[to][dir_now][nstate] == 0){
						q.push(to); q.push(dir_now); q.push(nstate);
						in[to][dir_now][nstate] = 1;
					}
				}
				if(to == ed && dis[to][dir_now][1] > dis[from][dir_pre][state] + 2*d[from][i]){
					dis[to][dir_now][1] = dis[from][dir_pre][state] + 2*d[from][i];
					if(in[to][dir_now][1] == 0){
						q.push(to); q.push(dir_now); q.push(1);
						in[to][dir_now][1] = 1;
					}
				}
			}
			else{
				nstate = 1;
				len *= 2;
				if(state == 0){
					len += get_len(from, dir_pre);//printf("len=%d\n", len);
				}
				if(dis[to][dir_now][nstate] > dis[from][dir_pre][state] + len){
					dis[to][dir_now][nstate] = dis[from][dir_pre][state] + len;
					if(in[to][dir_now][nstate] == 0){
						q.push(to); q.push(dir_now); q.push(nstate);
						in[to][dir_now][nstate] = 1;
					}
				}
			}
		}
	}
	int ans = 1e9;
	for(int i = 0; i < 5; i++)
		ans = min(ans, dis[ed][i][1]);
	return ans;
}

int main(){
	while(scanf("%d%d%d%d%d%d", &n, &m, &sti, &stj, &edi, &edj), n+m+sti+stj+edi+edj > 0){
		for(int i = 0; i <= 20000; i++)
			l[i].clear(), d[i].clear();
		for(int i = 1; i < 2*n; i++){
				int I = i / 2 + 1;
			if(i%2)
				for(int j = 1; j < m; j++){
					scanf("%d", &x);
					if(!x)
						continue;
					l[I*m+j].push_back(I*m+j+1);
					l[I*m+j+1].push_back(I*m+j);
					d[I*m+j].push_back(x);
					d[I*m+j+1].push_back(x);
				}
			else
				for(int j = 1; j <= m; j++){
					scanf("%d", &x);
					if(!x)
						continue;
					l[I*m+j].push_back((I-1)*m+j);
					l[(I-1)*m+j].push_back(I*m+j);
					d[I*m+j].push_back(x);
					d[(I-1)*m+j].push_back(x);
				}
		}
		int ans = SPFA(sti*m+stj, edi*m+edj);
		if(ans == 1e9)
			printf("Case %d: Impossible\n", ++ct);
		else
			printf("Case %d: %d\n", ++ct, ans);
	}
	return 0;
}
