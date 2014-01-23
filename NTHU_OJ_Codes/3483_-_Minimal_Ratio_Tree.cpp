#include<stdio.h>
#include<queue>
using namespace std;
typedef struct point{
	int a, b, w;
	bool operator < (const point &x) const{
		return w > x.w;
	}
}P;
int node[100], temp[100], n, m, pos[100], s[100][100], g[100];
int find_(int x){
	return g[x] == x ? x : (g[x] = find_(g[x]));
}
void toarray(int x, int temp[], int pos[]){
	for(int i = 0, ct = 0; i < n; i++)
		if(1 & (x >> i))
			temp[ct] = node[i], pos[ct++] = i;
}
int mst(int pos[]){
	P temp;
	int tot = 0;
	priority_queue<P> q;
	for(int i = 0; i < m; i++)
		for(int j = i+1; j < m; j++){
			temp.a = pos[j];
			temp.b = pos[i];
			temp.w = s[pos[j]][pos[i]];
			q.push(temp);
		}
	for(int i = 0; i < n; i++)
		g[i] = i;
	for(int i = 0; i < m - 1; i++){
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
	return tot;
}
int main(){
	while(scanf("%d%d", &n, &m), m + n){
		int ans;
		double min_ratio = 1e9;
		for(int i = 0; i < n; i++)
			scanf("%d", &node[i]);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n ; j++)
				scanf("%d", &s[i][j]);
		for(int i = 1; i < 1 << n; i++){
			int ct = 0;
			for(int j = 0; j < n; j++)
				ct += 1 & (i >> j);
			if(ct == m){
				toarray(i, temp, pos);
				double tot = 0;
				for(int k = 0; k < m; k++)
					tot += temp[k];
				double ratio_ = mst(pos) / tot;
				if(ratio_ < min_ratio)
					min_ratio = ratio_, ans = i;
			}
		}
		toarray(ans, temp, pos);
		printf("%d", pos[0]+1);
		for(int i = 1; i < m; i++)
			printf(" %d", pos[i]+1);
		putchar(10);
	}
	return 0;
}
