#include<cstdio>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<iostream>
#include<sstream>
#include<queue>
using namespace std;

int s[101];
bool rec[101][100001];
int main(){
	int n;
	while(scanf("%d", &n) > 0){
		memset(rec, 0, sizeof(rec));
		for(int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		int sx, sy, ex, ey, ans;
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		queue<int> q;
		q.push(sx), q.push(sy);q.push(0);
		while(!q.empty()){
			int x = q.front();q.pop();
			int y = q.front();q.pop();
			int mv = q.front();q.pop();
			if(x == ex){
				ans = mv;
				break;
			}
			if(y > 0 && !rec[x][y-1]){//<-
				rec[x][y-1] = 1;
				q.push(x), q.push(y-1), q.push(mv+1);
			}
			if(y <= s[x] && s[x] > 0 && !rec[x][y+1]){//->
				rec[x][y+1] = 1;
				q.push(x), q.push(y+1), q.push(mv+1);
			}
			if(x < n){//down
				int y_ = s[x+1]+1;
				rec[x+1][min(y, y_)] = 1;
				q.push(x+1), q.push(min(y, y_)), q.push(mv+1);
			}
			if(x > 0){//up
				int y_ = s[x-1]+1;
				rec[x-1][min(y, y_)] = 1;
				q.push(x-1), q.push(min(y, y_)), q.push(mv+1);
			}
			printf("mv=%d\n", mv);
		}
		printf("%d\n", ans);

	}
	return 0;
}
