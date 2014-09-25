#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#define REC map<int, vector<pair<int, int> > >
using namespace std;

int s[1000][1000], h, w, d, gg, rec[501][501], ct;
int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
int in(int i, int j) {
	return i >= 0 && i < h && j >= 0 && j < w;
}
void dfs(int i, int j, int h) {
	rec[i][j] = h;
	ct += s[i][j] == h;
	for (int k = 0; k < 4; k++) {
		int ii = i + di[k], jj = j + dj[k];
		if (in(ii, jj)) {
			if (rec[ii][jj] < 0 && s[ii][jj] > h - d && s[ii][jj] <= h)
				dfs(ii, jj, h);
			else if (rec[ii][jj] > h)
				gg = 0;
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		REC M;
		memset(rec, -1, sizeof(rec));
		scanf("%d%d%d", &h, &w, &d);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				scanf("%d", &s[i][j]);
				M[s[i][j]].push_back(make_pair(i, j));
			}
		REC::iterator it = M.end();

		int ans = 0;
		do {
			it--;
			int hh = it -> first;
			for (int k = 0; k < it -> second.size(); k++) {
				int ii = it -> second[k].first;
				int jj = it -> second[k].second;
				if (rec[ii][jj] < 0) {
					gg = 1;
					ct = 0;
					dfs(ii, jj, hh);
					ans += gg * ct;
				}
			}
		} while (it != M.begin());
		printf("%d\n", ans);
	}
	return 0;
}