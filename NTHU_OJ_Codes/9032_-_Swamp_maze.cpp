#include<cstdio>
#include<cstring>
#include<queue>
#define MAX 11000
#define pos(x,y) ((x-1)*m+y-1)
using namespace std;
int dis[MAX], in[MAX], d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int st, ed, t, n, m;
char s[110][110];

int main(){
	scanf("%d", &t);
	while(t--){
		memset(s, 0, sizeof(s));
		scanf("%d%d", &n, &m);
		for(int i = 0; i <= (n+1)*m+1; i++)
			dis[i] = 1e9, in[i] = 0;
		for(int i = 1; i <= n; i++)
			scanf("%s", s[i]+1);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++){
				if(s[i][j] == 'S')
					st = pos(i, j);
				else if(s[i][j] == 'G')
					ed = pos(i, j);
			}
		queue<int> q;
		q.push(st);
		dis[st] = 0;
		while(!q.empty()){
			int x = q.front(); q.pop();
			in[x] = 0;
			int i = x / m + 1, j = x % m + 1;
			for(int k = 0; k < 4; k++){
				int di = i + d[k][0], dj = j + d[k][1];
				if(s[di][dj] != 0 && s[di][dj] != '#'){
					int len =  ((s[di][dj] == '@') ? 2 : 1);
					int y = pos(di, dj);
					if(dis[y] > dis[x] + len){
						dis[y] = dis[x] + len;
						if(!in[y])
							in[y] = 1, q.push(y);
					}
				}
			}
		}
		printf("%d\n", dis[ed] == 1e9 ? -1 : dis[ed]);
	}
	return 0;
}
