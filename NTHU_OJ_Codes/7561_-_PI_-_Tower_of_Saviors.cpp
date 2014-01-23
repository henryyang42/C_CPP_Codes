#include<stdio.h>

#include<string.h>
char s[10][10];
char isvisit[10][10];
int ct;
int di[] = {1, 0,0,-1};
int dj[] = {0,-1,1, 0};
void dfs(char c, int i, int j, int del){
	int k;
	ct++;
	isvisit[i][j] = 1;
	if(del)
		s[i][j] = 0;
	for(k = 0; k < 4; k++){
		int x = i + di[k], y = j + dj[k];
		if(x >= 0 && x < 5 && y >= 0 && y < 6 && s[x][y] == c && !isvisit[x][y])
			dfs(c, x, y, del);
	}
}
void drop(){
	int i, j;
	int ct[6] = {4, 4, 4, 4, 4, 4};
	char temp[10][10] = {0};
	for(i = 4; i >= 0; i--)
		for(j = 0; j < 6; j++)
			if(s[i][j])
				temp[ct[j]--][j] = s[i][j];
	memcpy(s, temp, sizeof(temp));
}
int main(){
 char str[100];
 int t, tt = 0;
	while(scanf("%s%d", str, &t) > 0){
		printf("%s %d\n", str, t);

		int i, j;
		for(i = 0; i < 5; i++)
			scanf("%s", s[i]);
		int fg = 1;
		while(fg){
			fg = 0;
			for(i = 0; i < 5; i++)
				for(j = 0; j < 6; j++)if(s[i][j]){
					ct = 0;
					memset(isvisit, 0, sizeof(isvisit));
					dfs(s[i][j], i, j, 0);
					memset(isvisit, 0, sizeof(isvisit));
					if(ct >= 3)
						dfs(s[i][j], i, j, 1), fg++;
				}
			/*for(i = 0; i < 5; i++, putchar(10))
			for(j = 0; j < 6; j++)
				if(!s[i][j]) putchar('_');
				else putchar(s[i][j]);putchar(10);*/
			drop();
		}

		for(i = 0; i < 5; i++, putchar(10))
			for(j = 0; j < 6; j++)
				if(!s[i][j]) putchar('_');
				else putchar(s[i][j]);
		putchar(10);
	}
	return 0;
}
