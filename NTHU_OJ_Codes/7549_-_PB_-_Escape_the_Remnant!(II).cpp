#include<stdio.h>
#include<string.h>
#include<queue>
struct p{
	int x, y, z, ct;
}temp, now;
using namespace std;
int dx[] = {1, 0,-1, 0, 0, 0};
int dy[] = {0, 1, 0,-1, 0, 0};
int dz[] = {0, 0, 0, 0, 1,-1};
int main(){
	int ii, jj, kk, T;
	while(scanf("%d%d%d%d", &kk, &ii, &jj, &T) > 0, kk + ii + jj + T){
		int m, n, xa, xb, ya, yb, za, zb, x, y, k, i, j;
		char map[100][100][100] = {0};
		queue<p> q;
		for(k = 0; k < kk; k++)
			for(i = 0; i < ii; i++)
				scanf("%s", map[k][i]);
		for(k = 0; k < kk; k++)
			for(i = 0; i < ii; i++)
				for(j = 0; j < jj; j++){
					if(map[k][i][j] == 'S')
						xa = i, ya = j, za = k, map[k][i][j] = 0;
					if(map[k][i][j] == 'E')
						xb = i, yb = j, zb = k, map[k][i][j] = 0;
					if(map[k][i][j] == '.')
						map[k][i][j] = 0;
					if(map[k][i][j] == '#')
						map[k][i][j] = 1;
				}
		temp.x = xa, temp.y = ya, temp.z = za, temp.ct = 0;
		q.push(temp);
		while(!q.empty() && !(q.front().z == zb && q.front().x == xb && q.front().y == yb)){
			now = q.front();
			q.pop();
			for(i = 0; (i + 1) * T < now.ct && i < kk; i++)
				memset(map[i], 1, sizeof(map[i]));
			if((now.z + 1) * T >= now.ct)
			for(i = 0; i < 6; i++)
				if(now.x + dx[i] >= 0 && now.x + dx[i] < ii && now.y + dy[i] >= 0 && now.y + dy[i] < jj &&
				now.z + dz[i] >= 0 && now.z + dz[i] < kk && map[now.z + dz[i]][now.x + dx[i]][now.y + dy[i]] == 0)
					temp.x = now.x + dx[i], temp.y = now.y + dy[i], temp.z = now.z + dz[i], temp.ct = now.ct + 1, q.push(temp), map[temp.z][temp.x][temp.y] = 1;
		}
		if(q.front().x == xb && q.front().y == yb && q.front().z == zb && (q.front().z + 1) * T >= q.front().ct)
			printf("Successfully escaped in %d second(s)!\n", q.front().ct);
		else
			puts("They are doomed QAQ!");
	}
	return 0;
}
