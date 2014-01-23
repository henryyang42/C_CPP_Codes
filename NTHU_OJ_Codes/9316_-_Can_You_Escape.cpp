#include<stdio.h>
#include<queue>
#include<stdlib.h>
#include<string.h>
#define MAX 4001
using namespace std;
char map[MAX][MAX], temp[MAX][MAX];
int find(int ii, int jj, char temp[MAX][MAX], int n, int m, char c){
	int di[] = {1, 0,-1, 0};
	int dj[] = {0, 1, 0,-1};
	queue<int> i, j, ct;
	i.push(ii), j.push(jj), ct.push(0);
	while(!i.empty() && map[i.front()][j.front()] != c){
		for(int k = 0; k < 4; k++)
			if(i.front() + di[k] >= 0 && i.front() + di[k] < n &&
			j.front() + dj[k] >= 0 && j.front() + dj[k] < m && temp[i.front() + di[k]][j.front() + dj[k]] != 'w')
				i.push(i.front() + di[k]), j.push(j.front() + dj[k]), ct.push(ct.front() + 1), temp[i.front()+ di[k]][j.front() + dj[k]] = 'w';
		i.pop() ,j.pop(), ct.pop();
	}
	if(ct.empty())
		return -1;
	else
		return ct.front();
}
int main(){
	int n, m, i, j, Si, Sj, Ki, Kj, ans1, ans2, ct = 0;
	while(scanf("%d%d", &n, &m) > 0){
		for(i = 0; i < n; i++)
			scanf("%s", map[i]);
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				if(map[i][j] == 's')
					Si = i, Sj = j;
				else if(map[i][j] == 'b')
					Ki = i, Kj = j;
		memcpy(temp, map, sizeof(map));
		ans1 = find(Si, Sj, temp, n, m, 'b');
		memcpy(temp, map, sizeof(map));
		ans2 = find(Ki, Kj, temp, n, m, 'e');
		if(ans1 == -1 || ans2 == -1)
			puts("No solution.");
		else
			printf("Escape in %d steps.\n", ans1 + ans2);
	}
	return 0;
}
