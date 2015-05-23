#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
int v[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 
			//down, up, right, left
void _merge(int s[4][4], int dir){
	int di = v[dir][0], dj = v[dir][1];
	switch(dir){
		case 0:
		for(int i = 3; i >= 0; i--)
			for(int j = 0; j < 4; j++){
				int ii = i + di, jj = j + dj;
					if(ii >= 0 && ii < 4 && jj >= 0 && jj < 4){
						if(s[ii][jj] && s[i][j] == s[ii][jj])
							s[ii][jj] += s[i][j], s[i][j] = 0;
					}
			}
		break;
		case 1:case 3:
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++){
				int ii = i + di, jj = j + dj;
					if(ii >= 0 && ii < 4 && jj >= 0 && jj < 4){
						if(s[ii][jj] && s[i][j] == s[ii][jj])
							s[ii][jj] += s[i][j], s[i][j] = 0;
					}
			}
		break;
		case 2:
		for(int i = 0; i < 4; i++)
			for(int j = 3; j >= 0; j--){
				int ii = i + di, jj = j + dj;
					if(ii >= 0 && ii < 4 && jj >= 0 && jj < 4){
						if(s[ii][jj] && s[i][j] == s[ii][jj])
							s[ii][jj] += s[i][j], s[i][j] = 0;
					}
			}
		break;
	}
}
void _move(int s[4][4], int dir){
	int mv = 1, di = v[dir][0], dj = v[dir][1];
	while(mv){
		mv = 0;
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++){
				int ii = i + di, jj = j + dj;
				if(ii >= 0 && ii < 4 && jj >= 0 && jj < 4){
					if(!s[ii][jj] && s[i][j])
						s[ii][jj] = s[i][j], s[i][j] = 0, mv = 1;
				}
			}
	}
}
void print(int s[4][4]){
	puts("+----+----+----+----+");
	for(int l = 0; l < 4; l++){
		puts("|    |    |    |    |");
		for(int j = 0; j < 4; j++){
			putchar('|');
			if(s[l][j] == 0)
				printf("    ");
			else{
				printf("%4d", s[l][j]);
			}
		}
		puts("|");
		puts("|    |    |    |    |");
		puts("+----+----+----+----+");
	}
}
int main(){
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int tt = 1; tt <= t; tt++){
		char op[4];
		int s[4][4] = {};
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				scanf("%d", &s[i][j]);
		scanf("%s", op);
		int dir = -1;
		for(int i = 0; i < 4; i++)
			if(op[0] == "v^><"[i])
				dir = i;
		_move(s, dir);
		_merge(s, dir);
		_move(s, dir);
		printf("Case #%d:\n", tt);
		print(s);
	}
	return 0;
}