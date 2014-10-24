#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int n, m;
	while (cin >> n >> m) {
		double ans = 0;
		for (int i = 1; i < n; i++) {
			double pos = (double)i / n * (n + m);
			ans += fabs(pos - floor(0.5 + pos)) / (m + n);
		}
		printf("%lf\n", ans * 10000);
	}
	return 0;
}