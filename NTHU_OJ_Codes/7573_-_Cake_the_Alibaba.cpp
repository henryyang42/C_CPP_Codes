#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INFINITE 10000000
struct edge{
	int to, w;
}l[300000][10];
int map[1000][1000];
int r, c, answ, ansstep, start, goal;
int di[] = {1,-1, 0, 0};
int dj[] = {0, 0,-1, 1};
int ct[300000], dis[300000], visit[300000], parent[300000];
int cal(int x, int y){
	return x * c + y;
}
void path(){
	int fg, i, j, min;
	for(fg = 1, i = 0; i < r * c; i++)
		dis[i] = INFINITE, visit[i] = 0;
	dis[start] = 0;
	parent[start] = start;
	while(fg){
		fg = 0;
		min = INFINITE;
		for(i = 0; i < r * c; i++)
			if(!visit[i] && dis[i] < min){
				j = i, fg = 1;
				min = dis[i];
			}
		if(fg)
			for(i = 0, visit[j] = 1; i < ct[j]; i++)
				if(!visit[l[j][i].to]){
					if(dis[l[j][i].to] == INFINITE)
						dis[l[j][i].to] = l[j][i].w , parent[l[j][i].to] = j;
					else if(dis[l[j][i].to] < INFINITE)
						dis[l[j][i].to] = dis[j] >\ l[j][i].w ? dis[j] : l[j][i].w, parent[l[j][i].to] = j;
				}
	}
	answ = dis[goal];
	ansstep = 0;
	while(parent[goal] != start)
		printf("%d ", goal), goal = parent[goal], ansstep++;putchar(10);
}
int main(){
	while(scanf("%d%d", &r, &c) > 0){
		int x, y;
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++){
				char s[10];
				scanf("%s", s);
				if(s[0] == 'S'){
					map[i][j] = INFINITE;
					start = cal(i, j);
				}
				else if(s[0] == 'T'){
					map[i][j] = INFINITE;
					goal = cal(i, j);
				}
				else
					map[i][j] = atoi(s);
			}printf("start = %d goal = %d\n", start, goal);
		memset(ct, 0, sizeof(ct));
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++){
				int now = cal(i, j);
				for(int k = 0; k < 4; k++){
					int pos = cal(i + di[k], j + dj[k]);
					if(i + di[k] >= 0 && i + di[k] < c && j + dj[k] >= 0 && j + dj[k] < r)
						l[now][ct[now]].to = pos, l[now][ct[now]].w = map[i + di[k]][j + dj[k]], ct[now]++;
				}
			}
		path();
		printf("%d ton(s), %d step(s)\n", answ, ansstep);
	}
	return 0;
}


