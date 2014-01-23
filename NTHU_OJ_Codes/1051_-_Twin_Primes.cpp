#include<cstdio>
#define MAX 20000001
char s[MAX];
int ans[MAX/10], ct;

int main(){
	for(int i = 2; i < MAX; i++)
		if(!s[i])
			for(int j = i+i; j < MAX; j += i)
				s[j] = 1;
	for(int i = 3; i < MAX; i += 2)
		if(s[i] + s[i+2] == 0)
			ans[ct++] = i;
	int n;
	while(scanf("%d", &n) > 0)
		printf("(%d, %d)\n", ans[n-1], ans[n-1]+2);
	return 0;
}
