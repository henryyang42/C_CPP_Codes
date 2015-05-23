#include<stdio.h>
#include<queue>
using namespace std;
int t, n, m, g[1001];
typedef struct point{
	int a, b, w;
	bool operator < (const point &x) const{
		return w > x.w;
	}
}P;
int find_(int x){
	return g[x] == x ? x : (g[x] = find_(g[x]));
}
int main(){
	scanf("%d", &t);
	while(t--){
		P temp;
		priority_queue<P> q;
		scanf("%d%d", &n, &m);
		while(m--){
			scanf("%d%d%d", &temp.a, &temp.b, &temp.w);
			q.push(temp);
		}
		int tot = 0;
		for(int i = 0; i <= n; i++)
			g[i] = i;
		for(int i = 0; i < n - 1; i++){
			while(!q.empty()){
				temp = q.top();
				q.pop();
				if(find_(temp.a) != find_(temp.b)){
					g[find_(temp.a)] = find_(temp.b);
					tot += temp.w;
					break;
				}
			}
		}
		printf("%d\n", tot);
	}
	return 0;
}

