#include<stdio.h>
#include<string.h>
char s[10][10], temp[10][10], ct[256], c;
int di[] = {1, 0,-1, 0};
int dj[] = {0, 1, 0,-1};

void dfs(int i, int j){
	if(temp[i][j] == 'O' || temp[i][j] == 'X'){
		ct[temp[i][j]] = 1;
		temp[i][j] = 1;
		return;
	}
	temp[i][j] = 1;
	for(int k = 0; k < 4; k++)
		if(i + di[k] >= 0 && j + dj[k] >= 0 && i + di[k] < 9 && j + dj[k] < 9 && temp[i + di[k]][j + dj[k]] != 1)
			dfs(i + di[k], j + dj[k]);
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int black = 0, white = 0;
		for(int i = 0; i < 9; i++)
			scanf("%s", s[i]);
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++){
				ct['O'] = ct['X'] = 0;
				memcpy(temp, s, sizeof(temp));
				c = temp[i][j];
				temp[i][j] = 0;
				dfs(i, j);
				if(ct['O'] + ct['X'] == 1){
					if(ct['O'])
						white++;
					if(ct['X'])
						black++;
				}
				else{
					if(c == 'O')
						white++;
					if(c == 'X')
						black++;

				}
			}
		printf("Black %d White %d\n", black, white);
	}
	return 0;
}
