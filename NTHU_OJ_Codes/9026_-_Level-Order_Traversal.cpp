#include<stdio.h>
#include<queue>
using namespace std;
int main(){
	int t, n, r, i, a, b, fg = 0;
	scanf("%d", &t);
	while(t--){
		char map[1001][1001] = {0}, ct[1001] = {0};
		queue<int> q;
		scanf("%d%d", &n, &r);
		for(i = 0; i < n - 1; i++)
			 scanf("%d %d", &a, &b), map[a][b] = 1, map[b][a] = 1;
		q.push(r);
		if(fg)
			putchar(10);
		printf("Case %d:", ++fg);
		while(!q.empty()){
			ct[q.front()] = 1;
			printf(" %d", q.front());
			for(i = 1; i <= n; i++)
				if(map[q.front()][i] && !ct[i])
					q.push(i);
			q.pop();	
		}
		putchar(10);
	}
	return 0;
}
