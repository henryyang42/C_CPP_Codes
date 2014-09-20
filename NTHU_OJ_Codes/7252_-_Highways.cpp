#include<stdio.h>
#include<stdlib.h>

int leader[1010], V;
struct point{
	int x, y, dis;
}p[1010], dist[1000000];
int compare(const void *v, const void *o){
	return ((point*)v) -> dis - ((point*)o) -> dis;
}
int find_(int x){
	while(x != leader[x])
		x = leader[x];
	return x;
}

int main(){
	int n, q, t, a, b, f = 0;
	scanf("%d", &t);
	while(t--){
		if(f++) putchar(10);
		scanf("%d", &n);
		V = n - 1;
		for(int i = 0; i < n; i++)
			scanf("%d%d", &p[i].x, &p[i].y);
		scanf("%d", &q);
		for(int i = 1; i <= n; i++)
			leader[i] = i;
		for(int i = 0; i < q; i++){
			scanf("%d%d", &a, &b);
			int fa = find_(a), fb = find_(b);
			if(fa != fb)
				leader[fa] = fb, V--;
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				dist[i *n + j].x = i + 1, dist[i *n + j].y = j + 1, dist[i * n + j].dis = (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
		qsort(dist, n * n, sizeof(point), compare);
		if(!V)
			puts("No new highways need");
		else{
			int i = 0;
			while(V--){
				while(1){
					int fa = find_(dist[i].x), fb = find_(dist[i].y);
					if(fa != fb){
						printf("%d %d\n", dist[i].x, dist[i].y);
						leader[fa] = fb;
						break;
					}
					i++;
				}
			}
		}
	}
	return 0;
}
