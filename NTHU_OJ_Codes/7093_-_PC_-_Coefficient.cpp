#include<stdio.h>
long long int s[101][101], i, j;
int main(){
	s[0][0] = 1, s[1][0] = 1, s[1][1] = 1;
	for(i = 0; i <= 100; i++)
		s[i][0] = 1;
	for(i = 1; i <= 100; i++)
		for(j = 1; j <= 100; j++)
			s[i][j] = s[i - 1][j] + s[i - 1][j - 1];
	int m, n;
	while(scanf("%d%d", &m, &n) > 0)
		printf("%lld\n", s[m][n]);
	return 0;
}
