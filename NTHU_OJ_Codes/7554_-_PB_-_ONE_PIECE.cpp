#include<stdio.h>
#include<queue>
using namespace std;
struct map{
	char s[9][8];
}init;
int abs(int a){
	return a >= 0 ? a  : -a;
}
int di[] = {1, 1, 1, 0, 0,-1,-1,-1};
int dj[] = {1, 0,-1, 1,-1, 1, 0,-1};
int fg = 1;
int move_S(char s[9][8], int k){
	int x = -1, y = -1, x_ = -10, y_ = -10;
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 8; j++)
			if(s[i][j] == 'S')
				x_ = x = i, y_ = y = j;
	x_ += di[k], y_ += dj[k];
	if(x_ >= 0 && x_ < 9 && y_ >= 0 && y_ < 8){
		if(s[x_][y_] != '.')
			return 0;
		s[x_][y_] = s[x_][y_]^s[x][y];
		s[x][y] = s[x_][y_]^s[x][y];
		s[x_][y_] = s[x_][y_]^s[x][y];
		return 1;
	}
	return 0;
}
int move_E(char s[9][8]){
	int sz = 0;
	int p[100][2], pS[2];
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 8; j++)
			if(s[i][j] == 'E')
				p[sz][0] = i, p[sz][1] = j, s[i][j] = '.', sz++;
			else if(s[i][j] == 'S')
				pS[0] = i, pS[1] = j;
	for(int t = 0; t < sz; t++){
		int _x, _y, min = 100, temp;
		for(int i = 0; i < 8; i++){
			int x = p[t][0] + di[i], y = p[t][1] + dj[i];
			if((temp = abs(x - pS[0]) + abs(y - pS[1])) < min)
				min = temp, _x = x, _y = y;
		}
		if(_x >= 0 && _x < 9 && _y >= 0 && _y < 8)
			if(s[_x][_y] == '.')
				s[_x][_y] = 'E';
			else
				s[_x][_y] = '#';
	}
	return sz;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		for(int i = 0; i < 9; i++)
			scanf("%s", init.s[i]);
		queue<map> q;
		q.push(init);
		int win = 0;
		while(!q.empty() && !win){
			map now = q.front();
			q.pop();
			int test1 = 0, test2 = 0;
			for(int i = 0; i < 9; i++)
				for(int j = 0; j < 8; j++)
					if(now.s[i][j] == 'S')
						test1++;
					else if(now.s[i][j] == 'S')
						test2++;
			if(!test1 && !test2)
				continue;
			for(int i = 0; i < 8; i++){
				map temp = now;
				if(!move_S(temp.s, i))
					continue;
				if(!move_E(temp.s)){
					win = 1;
					break;
				}
				q.push(temp);
			}
		}
		if(!win)
			puts("Oh no! I'm a dead man!");
		else
			puts("I'm the king of the Seven Seas!");
	}
	return 0;
}
