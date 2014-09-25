#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int h, n, s[100][100], rec[10000], e[100];
void shift(int s[], int x) {
	int t[100];
	for (int i = 0; i < n; i++)
		t[i] = s[(i + x) % n];
	for (int i = 0; i < n; i++)
		s[i] = t[i];
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(rec, -1, sizeof(rec));
		memset(e, 0, sizeof(e));
		scanf("%d%d", &h, &n);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &s[i][j]);
				if (s[i][j] > 0)
					rec[s[i][j]] = i;
			}
		}
		//for(int i = 0; i < h; i++)
		//  s[i][0] = 1e9;
		int x = 1, ans = 0;
		while (rec[x] >= 0) { //printf("%d ", x);
			ans += rec[x] * 20;
			int ev, car;
			for (int i = 0; i < n; i++)
				if (x == s[rec[x]][i]) {
					car = i;
				}
				else if (1e9 == s[rec[x]][i])
					ev = i;
			int d = abs(car - n);
			//e[rec[x]] = (e[rec[x]] + d) % n;

			ans += 5 * min(d, n - d);
			shift(s[rec[x]], car);
			x++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
