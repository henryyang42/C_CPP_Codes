#include<stdio.h>
char s[11][(1<<10)+1][(1<<11)+1];
int main(){
	for(int i = 1; i <= 10; i++)
		for(int j = 0; j <= 1024; j++)
			for(int k = 0; k <= 2048; k++)
				s[i][j][k] = ' ';
	s[1][0][0] = s[1][1][1] = '/';
	s[1][0][3] = s[1][1][2] = '\\';
	s[1][0][1] = s[1][0][2] = '_';
	for(int n = 2; n <= 10; n++){
		for(int i = 0; i < 1 << (n-1); i++)
			for(int j = 0; j < 1 << n; j++)
				s[n][i][j] = s[n][i][j+(1<<n)] = s[n][i+(1<<(n-1))][j+(1<<(n-1))] = s[n-1][i][j];

	}
	int n;
	while(scanf("%d", &n), n){
		for(int i = (1 << n)-1; i >= 0; i--, putchar(10))
			for(int j = 0; j < (1<<(n+1)) - i; j++)
				putchar(s[n][i][j]);
		putchar(10);
	}
	return 0;
}
