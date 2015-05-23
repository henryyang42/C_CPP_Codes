#include<stdio.h>
#include<queue>
struct p{
	int x, y, ct;	
}temp, now;
using namespace std;
int dx[] = {2, 2,-1,-1,-2,-2, 1, 1};
int dy[] = {1,-1, 2,-2, 1,-1,-2, 2};
int main(){
	char point1[3], point2[3];
	while(scanf("%s%s", point1, point2) > 0){
		int m = 8, n = 8, xa, xb, ya, yb, x, y, k, i;
		char map[102][102] = {0};
		queue<p> q;
		xa = point1[0] - 'a', ya = point1[1] - '0' - 1;
		xb = point2[0] - 'a', yb = point2[1] - '0' - 1;
		temp.x = xa, temp.y = ya, temp.ct = 0;
		q.push(temp);
		while(!q.empty() && !(q.front().x == xb && q.front().y == yb)){
			now = q.front();
			q.pop();
			for(i = 0; i < 8; i++)
				if(now.x + dx[i] >= 0 && now.x + dx[i] < m && now.y + dy[i] >= 0 && now.y + dy[i] < n && map[now.x + dx[i]][now.y + dy[i]] == 0)
					temp.x = now.x + dx[i], temp.y = now.y + dy[i], temp.ct = now.ct + 1, q.push(temp), map[temp.x][temp.y] = 1;
		}
		if(q.front().x == xb && q.front().y == yb)
			printf("To get from %s to %s takes %d knight moves.\n", point1, point2, q.front().ct);
		else
			puts("-1");
	}
	return 0;
}
