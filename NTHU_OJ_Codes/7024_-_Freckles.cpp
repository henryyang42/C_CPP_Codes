#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n, t, g[1001], ct;
double point[101][2];
struct P{
	int a, b;
	double dis;
}line[10001];
bool cmp(P x, P y){
	return x.dis < y.dis;
}
double dist(double a[2], double b[2]){
	return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
}
int find_(int x){
	return x == g[x] ? x : (g[x] = find_(g[x]));
}

int main(){
	scanf("%d", &t);
	while(t--){
		ct = 0;
		scanf("%d", &n);
		for(int i = 0; i <= n; i++)
			g[i] = i;
		for(int i = 0; i < n; i++)
			scanf("%lf%lf", &point[i][0], &point[i][1]);
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				line[ct].a = i+1, line[ct].b = j+1, line[ct++].dis = dist(point[i], point[j]);
		sort(line, line+ct, cmp);
		double tot = 0;
		int take = 0;
		for(int i = 0; i < ct; i++){
			int pa = find_(line[i].a), pb = find_(line[i].b);
			if(pa != pb){
				take++;
				tot += sqrt(line[i].dis);
				g[pa] = pb;
			}
			if(take == n-1)
				break;
		}
		printf("%.2lf\n", tot);
		if(t)
			putchar(10);
	}
	return 0;
}

