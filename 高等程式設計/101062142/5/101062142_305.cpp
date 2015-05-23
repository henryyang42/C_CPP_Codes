#include <cstdio>
#include <queue>
using namespace std;
int ans[14];
int main(){
	int n;
	for(n = 1; n < 14; n++){
		int m = 1;
		while(1){
			queue<int> q;
			int sz = 2*n, valid = 1;
			for(int i = 1; i <= 2*n; i++)
				q.push(i);
			for(int i = 0; i < n && valid; i++){
				int x, l = (m-1+sz)%sz;
				for(int j = 0; j < l; j++)
					x = q.front(), q.pop(), q.push(x);
				x = q.front();
				q.pop();
				valid = x > n && x <= 2*n;
				sz--;
			}
			if(valid)
				break;
			m++;
		}
		ans[n] = m;
	}
	
	while(scanf("%d", &n), n){
		printf("%d\n", ans[n]);
	}
	return 0;
}