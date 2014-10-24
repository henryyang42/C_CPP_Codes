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
	unsigned long long m, n;
	while (scanf("%llu%llu", &n, &m), n + m > 0) {
		if (n > m)
			swap(n, m);
		printf("%llu\n", (n * m * (m - 1) + (3 * m - 2 * n + 2) * n * (n - 1)) + (4 * (n - 1) * (n) * (n - 2)) / 3);
	}
	return 0;
}