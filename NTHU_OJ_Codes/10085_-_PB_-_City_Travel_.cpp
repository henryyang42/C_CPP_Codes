#include <stdio.h>
#include <cstring>
#include <queue>

using namespace std;

int main() {
	int t, n, m, k, p, a, b, dis, c, i, j;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d %d", &n, &m, &k, &p);
		int adj[60][60][2] = {};
		while (m--) {
			scanf("%d %d %d %d", &a, &b, &dis, &c);
			adj[a][b][0] = adj[b][a][0] = dis;
			adj[a][b][1] = adj[b][a][1] = c;
		}
		while (p--) {
			int in[60][60] = {};
			scanf("%d %d", &a, &b);
			queue<int> q;
			int rec[60][60] = {};
			for (i = 1; i <= n; i++)
				for (j = 1; j <= k; j++)
					rec[i][j] = 1e9;
			for (i = 1; i <= n; i++) {
				rec[a][i] = 0; // It work wonder! But I don't know why... Magic~
				if (adj[a][i][0]) {
					rec[i][adj[a][i][1]] = adj[a][i][0];
					q.push(i);
					q.push(adj[a][i][1]);
					in[i][adj[a][i][1]] = 1;
				}
			}
			int mini = 1e9;

			while (!q.empty()) {
				int x = q.front(); q.pop();
				int con = q.front(); q.pop();
				in[x][con] = 0;
				for (i = 1; i <= n; i++) {
					if (adj[x][i][0] && adj[x][i][1] != con) {
						if (rec[x][con] + adj[x][i][0] < rec[i][adj[x][i][1]]) {
							rec[i][adj[x][i][1]] = rec[x][con] + adj[x][i][0];
							if (!in[i][adj[x][i][1]]) {
								in[i][adj[x][i][1]] = 1;
								q.push(i);
								q.push(adj[x][i][1]);
							}
						}
					}
				}
			}
			for (int i = 1; i <= k; i++)
				mini = min(mini, rec[b][i]);
			if (mini != 1e9)
				printf("%d\n", mini);
			else
				puts("infinity");
		}
	}
	return 0;
}