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
long long s[1000001], t[1000001], tot, x, ans;
int main(int argc, char *argv[]) {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int n;
	while (scanf("%d", &n) > 0) {
		ans = tot = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &s[i]);
			tot += s[i];
		}
		tot /= n;
		for (int i = 1; i < n; i++)
			t[i] = t[i - 1] + tot - s[i - 1];
		sort(t, t + n);
		x = t[n / 2];
		for (int i = 0; i < n; i++)
			ans += abs(t[i] - x);
		printf("%lld\n", ans);
	}

	return 0;
}