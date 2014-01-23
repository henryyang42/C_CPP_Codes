#include<stdio.h>
#include<algorithm>
#include<string.h>
int s[100], n, i, fg = 0, ct[100], temp[100];
void DFS(int level, int k){
	int i;
	if(level == 6){
		for(i = 0; i < 6; i++){
			if(i)
				putchar(32);
			printf("%d", temp[i]);	
		}
		putchar(10);
		return;
	}
	for(i = k; i < n; i++)
		if(ct[i] == 0){
			ct[i] = 1;
			temp[level] = s[i];
			DFS(level + 1, i + 1);
			ct[i] = 0;	
		}
}
int main(){
	while(scanf("%d", &n) > 0, n){
		if(fg++)
			putchar(10);
		for(i = 0; i < n; i++)
			scanf("%d", &s[i]);
		std::sort(s, s + n);
		memset(ct, 0, sizeof(ct));
		DFS(0, 0);
	}
	return 0;
}
