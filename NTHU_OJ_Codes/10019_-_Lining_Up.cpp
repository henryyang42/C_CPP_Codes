#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int x[1000], y[1000], t;
map<pair<int, int>, int> m;
int main(int argc, char *argv[]) {
	scanf("%d", &t);
	getchar();
	getchar();
	while (t--) {
		int n = 0, ans = 0;
		string str;
		while (getline(cin, str)) {
			if (str == "")
				break;
			stringstream ss;
			ss << str;
			ss >> x[n] >> y[n];
			n++;
		}
		for (int i = 0; i < n; i++) {
			m.clear();
			for (int j = 0; j < n; j++) {
				if (i == j)
					continue;
				int dx = x[i] - x[j], dy = y[i] - y[j];
				int gcd = __gcd(dx, dy);
				dx /= gcd, dy /= gcd;
				if (dx < 0)
					dx *= -1, dy *= -1;
				m[make_pair(dx, dy)]++;
				ans = max(ans, m[make_pair(dx, dy)]);
			}
		}
		printf("%d\n", ans + 1);
		if (t)
			putchar(10);
	}
	return 0;
}