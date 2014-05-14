#include<cstdio>
#include<cmath>
double p, q, r, s, t, u;

double f(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}


int main() {
	while (scanf("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u) > 0) {
		double low = 0, high = 1.0, mid;
		if (f(low)*f(high) > 0) {
			puts("No solution");
			continue;
		}
		int times = 1000;
		if (f(0) == 0)
			puts("0.0000");
		else if (f(1) == 0)
			puts("1.0000");
		else {
			while (times--) {
				mid = (low + high) / 2;
				double fmid = f(mid);
				if (fabs(fmid) < 1e-12)
					break;
				if (fmid * f(low) < 0)
					high = mid;
				else if (fmid * f(high) < 0)
					low = mid;
			}
			printf("%.4lf\n", mid);
		}
	}
	return 0;
}
