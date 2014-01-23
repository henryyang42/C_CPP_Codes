#include<stdio.h>
int t, n, m;
char s[1001][1001];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int x, int y){
	if(s[x][y] == '1')
		return;
	s[x][y] = '1';
	for(int i = 0; i < 4; i++)
		if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < m)
			dfs(x + dx[i], y + dy[i]);
}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++)
			scanf("%s", s[i]);
		char op[2];
		while(scanf("%s", op) > 0, op[0] != 'E'){
			int x1, x2, y1, y2, temp;
			switch(op[0]){
				case 'R':
					scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
					if(x1 > x2) temp = x1, x1 = x2, x2 = temp;
					if(y1 > y2) temp = y1, y1 = y2, y2 = temp;
					for(int x = x1; x <= x2; x++)
						s[n - y1 - 1][x] = s[n - y2 - 1][x] = '1';
					for(int y = y1; y <= y2; y++)
						s[n - y - 1][x1] = s[n - y - 1][x2] = '1';
					break;
				case 'F':
					scanf("%d%d", &x1, &y1);
					dfs(n - y1 - 1, x1);
					break;
				case 'L':
					scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
					if(x1 > x2) temp = x1, x1 = x2, x2 = temp;
					if(y1 > y2) temp = y1, y1 = y2, y2 = temp;
					if(x1 == x2)
						for(int y = y1; y <= y2; y++)
							s[n - y - 1][x1] = '1';
					if(y1 == y2)
						for(int x = x1; x <= x2; x++)
							s[n - y1 - 1][x] = '1';
			}
		}
		for(int x = 0; x < n; x++)
			puts(s[x]);
		putchar(10);
	}
	return 0;
}
