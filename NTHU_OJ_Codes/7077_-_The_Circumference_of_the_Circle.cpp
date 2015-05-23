#include<cstdio>
#include<cmath>
#define PI 3.14159265358979323
#define v(s,t) ((s-t)*(s-t))
int main(){
	double x[3], y[3], l[3];
	while(scanf("%lf%lf%lf%lf%lf%lf", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]) > 0){
		for(int i = 0; i < 3; i++)
			l[i] = sqrt(v(x[i],x[(i+1)%3])+v(y[i],y[(i+1)%3]));
		printf("%.2lf\n", l[0]*PI/sin(acos((l[1]*l[1]+l[2]*l[2]-l[0]*l[0])/(2.0*l[1]*l[2]))));
	}
	return 0;
}
