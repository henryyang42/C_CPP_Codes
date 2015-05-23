#include<stdio.h>
#include<algorithm>
#define PI 3.141592653589
using namespace std;
double q(double r, double h) {
	return PI * r * r * h;
}
int main() {
	double w, h;
	while (scanf("%lf%lf", &w, &h), w + h > 0) {
		printf("%.3lf\n", max(q(min(w / 2.0, h / (2.0 * PI + 2.0)), w),
		                      q(min(w / 2.0 / PI, h / 3), h - 2 * min(w / 2.0 / PI, h / 3))));
	}
	return 0;
}