#include<stdio.h>
#include<math.h>
#define pi acos(-1)
struct tri{
	double x, h, b;
}t[1000], temp;
double same(tri a, tri b){
	if(b.x < a.x)
		temp = b, b = a, a = temp;
	if(a.x + a.b <= b.x)
		return 0;
	double anga = atan2(a.b / 2.0, a.h), angb = atan2(b.b / 2.0, b.h), w = a.x + a.b - b.x;
	return w / sin(pi-anga-angb) * (sin(anga) + sin(angb));
}
int main(){
	int n, ct = 0;
	while(scanf("%d", &n), n){
		for(int i = 0; i < n; i++)
			scanf("%lf%lf%lf", &t[i].x, &t[i].h, &t[i].b);
		double ans = 0;
		for(int i = 0; i < n; i++){
			ans += 2 * sqrt(t[i].h*t[i].h + t[i].b*t[i].b / 4.0)+0.5;
			for(int j = i + 1; j < n; j++)
				ans -= same(t[i], t[j])+0.5;
		}
		printf("Case %d: %d\n\n", ++ct, (int)(ans + 0.5));
	}
	return 0;
}
