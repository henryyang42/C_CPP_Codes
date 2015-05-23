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
	int n, ct = 0;
	while (cin >> n, n > 0) {
		int k = 31 - __builtin_clz(n);
		printf("Case %d: %d\n", ++ct, k + (((1 << k)^n) > 0));
	}
	return 0;
}