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
struct Job {
	int a, b;
	bool operator < (const Job &x) const {
		return x.b < b;
	}
} s[1001];
int main(int argc, char *argv[]) {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int n, ct = 0;
	while (scanf("%d", &n), n) {
		for (int i = 0; i < n; i++)
			scanf("%d%d", &s[i].a, &s[i].b);
		sort(s, s + n);
		int ans = 0, tot = 0;
		for (int i = 0; i < n; i++)
			tot += s[i].a, ans = max(ans, tot + s[i].b);
		printf("Case %d: %d\n", ++ct, ans);

	}
	return 0;
}