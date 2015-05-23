#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int n, t;
double c[10010][3];
double F(double x) {
	double ans = c[0][0] * x * x + c[0][1] * x + c[0][2];
	for (int i = 1; i < n; i++)
		ans = max(ans, c[i][0] * x * x + c[i][1] * x + c[i][2]);
	return ans;
}
int main(int argc, char *argv[]) {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			scanf("%lf%lf%lf", &c[i][0], &c[i][1], &c[i][2]);
		double L = 0, R = 1000, m1, m2;
		for (int i = 0; i < 100; i++) {
			m1 = L + (R - L) / 3;
			m2 = R - (R - L) / 3;
			if (F(m1) > F(m2))
				L = m1;
			else
				R = m2;
		}
		printf("%.4lf\n", F(m1));
	}
	return 0;
}