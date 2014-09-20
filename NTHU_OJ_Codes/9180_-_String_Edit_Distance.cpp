#include<stdio.h>
#include<string.h>
#define MAX 4001
char s1[MAX], s2[MAX];
int s[MAX][MAX];
int min(int a, int b, int c){
	int m = 2147483647;
	if(m > a)
		m = a;
	if(m > b)
		m = b;
	if(m > c)
		m = c;
	return m;
}
int main(){
	int x;
	while(scanf("%s%s", s1, s2) > 0){
		int i, j, l1 = strlen(s1), l2 = strlen(s2);
		for(i = 0; i < MAX; i++)
			s[0][i] = i, s[i][0] = i;
		for(i = 0; i < l1; i++)
			for(j = 0; j < l2; j++)
				s[i+1][j+1] = min(s[i][j+1] + 1, s[i+1][j] + 1, s[i][j] + (s1[i] != s2[j]));
		printf("%d\n", s[l1][l2]);
	}
	return 0;
}
