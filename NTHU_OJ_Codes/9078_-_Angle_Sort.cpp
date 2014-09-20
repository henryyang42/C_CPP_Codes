#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct point{
	double angle;
	int i;
}p[100001], o;
int compare(const void*v, const void *o){
	double a = ((struct point*)v) -> angle, b = ((struct point*)o) -> angle;
	if(a > b)
		return 1;
	if(a < b)
		return -1;
	return 0;
}
int main(){
	int n, i;
	double x, y, ox, oy;
	while(scanf("%d", &n ) > 0){
		scanf("%lf%lf", &ox, &oy);
		for(i = 1; i <= n; i++){
			scanf("%lf%lf", &x, &y);
			p[i-1].i = i;
			x -= ox;
			y -= oy;
			p[i-1].angle = atan2(y, x);
			if(p[i-1].angle < 0)
				p[i-1].angle += 6.28318530717958647;
		}
		qsort(p, n, sizeof(struct point), compare);
		for(i = 0; i < n; i++){
			if(i)
				putchar(32);
			printf("%d", p[i].i);
		}
		putchar(10);
	}
	return 0;
}
