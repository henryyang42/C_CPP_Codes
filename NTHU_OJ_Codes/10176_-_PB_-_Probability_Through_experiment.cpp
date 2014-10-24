#include <cctype>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int t[100000];

int main() {
	int r;
	long long n, nn, casect = 0;
	while (scanf("%lld%d", &n, &r), n + r > 0) {
		nn = 0;
		for (int i = 0; i < n; i++) {
			int a, b;
			scanf("%d.%d", &a, &b);
			t[nn++] = a * 1000 + b;
			t[nn++] = a * 1000 + b + 360000;
		}
		sort(t, t + 2 * n);
		long long ans = (n * (n - 1) * (n - 2)) / 6LL, neg = 0, right = 0;

		int index = 0;
		for (int i = 0; i < n; i++) {
			long long ct = upper_bound(t, t + 2 * n, t[i] + 180000) - t - i - 1;
			neg += (ct * (ct - 1)) / 2LL;
		}
		printf("Case %lld: %lld\n", ++casect, ans - neg);
	}
	return 0;
}