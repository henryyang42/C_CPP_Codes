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
long long ans[1000010];
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	for (long long i = 4; i <= 1000000; i++) {
		long long t = i - 3;
		long long x = t / 2 + t % 2;
		ans[i] = ans[i - 1] + t * x - x * (x - 1);
	}
	int n;
	while (scanf("%d", &n), n >= 3)
		printf("%lld\n", ans[n]);
	return 0;
}