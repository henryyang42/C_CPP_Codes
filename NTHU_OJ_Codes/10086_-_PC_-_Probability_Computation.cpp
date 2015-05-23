#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;
int tt[400][400];
int main() {
	for (int i = 0; i < 300; i++)
		tt[0][i] = 1;

	for (int j = 1; j < 300; j++)for (int i = 1; i < 300; i++) {
			tt[i][j] = (2 * tt[i - 1][j]) % j;
		}


	int t;
	scanf("%d", &t);
	while (t--) {
		int n, Q, R;
		scanf("%d", &n);
		double s[2000];
		for (int i = 0; i < n; i++)
			scanf("%lf", &s[i]), s[i] /= 100.0;
		scanf("%d%d", &Q, &R);
		reverse(s, s + n);
		double dp[201][103] = {};
		dp[0][0] = 1.0 - s[0];
		dp[0][1] = s[0];
		for (int i = 1; i < n; i++)
			for (int j = 0; j < Q; j++) {
				dp[i][(j + tt[i][Q]) % Q] += dp[i - 1][j] * (s[i]);
				dp[i][j] += dp[i - 1][j] * (1.0 - s[i]);
				//printf("%lf\n", s[i]);
			}
		printf("%.5lf\n", dp[n - 1][R]);

	}
	return 0;
}
