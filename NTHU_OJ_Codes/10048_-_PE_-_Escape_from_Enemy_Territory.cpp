#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int s[1001][1001], h, w, n, a, b, st[2], ed[2];
int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
int dis[1001][1001]; //min dis. from bomb
int in(int i, int j) {
	return i >= 0 && j >= 0 && i < h && j < w;
}
int inq[1001][1001], rec[1001][1001][2] /*min from bomb, len*/;
void spfa() {
	memset(inq, 0, sizeof(inq));
	for (int i = 0; i <= h; i++)
		for (int j = 0; j <= w; j++)
			rec[i][j][0] = 0, rec[i][j][1] = 1e9;
	queue<int> q;
	q.push(st[0]), q.push(st[1]);
	rec[st[0]][st[1]][0] = dis[st[0]][st[1]];
	rec[st[0]][st[1]][1] = 0;
	while (!q.empty()) {
		int i = q.front(); q.pop();
		int j = q.front(); q.pop();
		int d = rec[i][j][0];
		int len = rec[i][j][1];
		inq[i][j] = 0;
		for (int k = 0; k < 4; k++) {
			int ii = i + di[k], jj = j + dj[k];
			if (in(ii, jj)) {
				int dd = min(dis[ii][jj], d);
				if (dd > rec[ii][jj][0]) {
					rec[ii][jj][0] = dd;
					rec[ii][jj][1] = len + 1;
					if (!inq[ii][jj])
						q.push(ii), q.push(jj), inq[ii][jj] = 1;
				}
				else if (dd == rec[ii][jj][0] && len + 1 < rec[ii][jj][1]) {
					rec[ii][jj][1] = len + 1;
					if (!inq[ii][jj])
						q.push(ii), q.push(jj), inq[ii][jj] = 1;
				}
			}
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(dis, -1, sizeof(dis));
		scanf("%d%d%d", &n, &h, &w);
		scanf("%d%d%d%d", &st[0], &st[1], &ed[0], &ed[1]);
		queue<int> q;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a, &b);
			q.push(a), q.push(b);
			dis[a][b] = 0;
		}
		while (!q.empty()) {
			int i = q.front(); q.pop();
			int j = q.front(); q.pop();
			int d = dis[i][j];
			for (int k = 0; k < 4; k++) {
				int ii = i + di[k], jj = j + dj[k];
				if (in(ii, jj) && dis[ii][jj] < 0) {
					dis[ii][jj] = d + 1;
					q.push(ii), q.push(jj);
				}
			}
		}
		spfa();
		printf("%d %d\n", rec[ed[0]][ed[1]][0], rec[ed[0]][ed[1]][1]);
	}
	return 0;
}