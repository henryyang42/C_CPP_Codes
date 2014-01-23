#include<stdio.h>
#include<queue>
struct p{
	int x, y, ct;	
}temp, now;
using namespace std;
int dx[] = {1, 0,-1, 0};
int dy[] = {0, 1, 0,-1};
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int m, n, xa, xb, ya, yb, x, y, k, i;
		char map[102][102] = {0};
		queue<p> q;
		scanf("%d%d", &m, &n);
		scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
		scanf("%d", &k);
		for(i = 0; i < k; i++)
			scanf("%d%d", &x, &y), map[x][y] = 1;
		temp.x = xa, temp.y = ya, temp.ct = 0;
		q.push(temp);
		while(!q.empty() && !(q.front().x == xb && q.front().y == yb)){
			now = q.front();
			q.pop();
			for(i = 0; i < 4; i++)
				if(now.x + dx[i] >= 0 && now.x + dx[i] < m && now.y + dy[i] >= 0 && now.y + dy[i] < n && map[now.x + dx[i]][now.y + dy[i]] == 0)
					temp.x = now.x + dx[i], temp.y = now.y + dy[i], temp.ct = now.ct + 1, q.push(temp), map[temp.x][temp.y] = 1;
		}
		if(q.front().x == xb && q.front().y == yb)
			printf("%d\n", q.front().ct);
		else
			puts("-1");
	}
	return 0;
}
