#include <cstdio>
#include <cmath>
#define F(x) (p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u)
#define eps 1e-14

int main() {
	double p, q, r, s, t, u;
	while (scanf("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u) > 0) {
		if (F(0) < -eps || F(1) > eps)
			puts("No solution");
		else {
			double upper = 1, mid, lower = 0;
			for (int i = 0; i < 100; i++) {
				mid = (upper + lower) / 2;
				if (F(mid) < 0) upper = mid;
				else lower = mid;
			}
			printf("%.4lf\n", mid);
		}
	}
	return 0;
}