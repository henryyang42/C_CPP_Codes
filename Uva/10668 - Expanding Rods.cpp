#include <cstdio>
#include <cmath>

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	double L, n, C, L2, R;
	const double pi = acos(-1);
	while (scanf("%lf%lf%lf", &L, &C, &n), n >= 0) {
		L2 =  (1 + n * C) * L;
		double lower = 0, upper = pi / 2, mid;
		for (int i = 0; i < 100 && lower <= upper; i++) {
			mid = (lower + upper) / 2;
			R = L / 2 / sin(mid);
			if (2 * R * mid < L2)
				lower = mid;
			else
				upper = mid;
		}
		printf("%.3lf\n", R - R * cos(mid));
	}
	return 0;
}
