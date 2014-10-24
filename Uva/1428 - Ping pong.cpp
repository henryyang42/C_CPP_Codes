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
#define lower_bit(x) (x&(-x))
#define MAX 100010
using namespace std;

int s[MAX], c[MAX], t, n;
long long ans, a1[MAX], a2[MAX];

void add(int x) {
	while (x < MAX)
		c[x] += 1, x += lower_bit(x);
}
int sum(int x) {
	int ret = 0;
	while (x > 0) {
		ret += c[x];
		x -= lower_bit(x);
	}
	return ret;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; i++) {
			add(s[i]);
			a1[i] = sum(s[i] - 1);
		}
		memset(c, 0, sizeof(c));
		for (int i = n - 1; i >= 0; i--) {
			add(s[i]);
			a2[i] = sum(s[i] - 1);
		}
		ans = 0;
		for (int i = 1; i < n - 1; i++) {
			ans += a1[i] * (n - i - 1 - a2[i]) + a2[i] * (i - a1[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}