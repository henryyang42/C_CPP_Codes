#include<stdlib.h>
#include<stdio.h>

int temp[301][301] = {0}, map[301][301] = {0}, z[90010][2], zero, tempz[90010][2], tobe[90010][3];
int dx[] = {1,-1, 0, 0};
int dy[] = {0, 0,-1, 1};
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int fg, x, y, id, i, j, n, m, k, ct[101] = {0};
		scanf("%d%d%d", &n, &m, &k);
		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				map[i][j] = temp[i][j] = 0;
		while(k--)
			scanf("%d%d%d", &x, &y, &id), map[x][y] = id;
		for(zero = 0, i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				if(!map[i][j])
					z[zero][0] = i, z[zero++][1] = j;
		fg = 1;
		while(fg){
			fg = 0;
			int tempct = 0, I, next = 0;
			for(I = 0; I < zero; I++){
				int i = z[I][0], j = z[I][1];
				for(k = 0; k < 4; k++){
					int x = i + dx[k], y = j + dy[k];
					if(x <= n && y <= m && (map[x][y] < temp[i][j] && map[x][y] || !temp[i][j] && map[x][y]))
						temp[i][j] = map[x][y], fg++;
				}
				if(temp[i][j])
					tobe[next][0] = i, tobe[next++][1] = j;
				else
					tempz[tempct][0] = z[I][0], tempz[tempct++][1] = z[I][1];
			}
			for(i = 0, zero = tempct; i < zero; i++)
				z[i][0] = tempz[i][0], z[i][1] = tempz[i][1];
			for(i = 0; i < next; i++)
				map[tobe[i][0]][tobe[i][1]] = temp[tobe[i][0]][tobe[i][1]];
			/*for(i = 1; i <= n; i++)
				for(j = 1; j <= m; j++){
					temp[i][j] = 0;
					if(!map[i][j])
						for(k = 0; k < 4; k++){
							int x = i + dx[k], y = j + dy[k];
							if(x <= n && y <= m && (map[x][y] < temp[i][j] && map[x][y] || !temp[i][j] && map[x][y]))
								temp[i][j] = map[x][y], fg++;
						}
					else
						temp[i][j] = map[i][j];
				}
			for(i = 1; i <= n; i++)
				for(j = 1; j <= m; j++)
					map[i][j] = temp[i][j];*/

		}
		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				ct[map[i][j]]++;
		i = 0;
		while(i++ < 100)
			if(ct[i])
				printf("%d\n", ct[i]);
		putchar(10);
	}
	return 0;
}
