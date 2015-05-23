#include<queue>
#include<cstdio>
#include<map>
#define INFINTY 2147483647
#define MAX 210
using namespace std;
int Jug[3], D;
map<int, map<int, map<int, int> > > visit;
int vol[MAX];
struct state {
	int jug[3], tot;
};
inline state move(state x, int i, int j) {
	//move from i to j
	if (x.jug[i] == 0 || x.jug[j] == Jug[j])
		return x;
	x.jug[j] += x.jug[i];
	x.tot += x.jug[i];
	x.jug[i] = 0;
	if (x.jug[j] > Jug[j]) {
		x.jug[i] = x.jug[j] - Jug[j];
		x.jug[j] = Jug[j];
		x.tot -= x.jug[i];
	}
	return x;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		visit.clear();
		for (int i = 0; i < MAX; i++)
			vol[i] = INFINTY;
		scanf("%d%d%d%d", &Jug[0], &Jug[1], &Jug[2], &D);
		state original = {0, 0, Jug[2], 0}, temp;
		queue<state> q;
		q.push(original);
		while (!q.empty()) {
			temp = q.front();
			q.pop();
			for (int i = 0; i < 3; i++)
				if (vol[temp.jug[i]] > temp.tot)
					vol[temp.jug[i]] = temp.tot;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					if (i != j) {
						state newstate = move(temp, i, j);
						for (int k = 0; k < 3; k++)
							if (vol[newstate.jug[k]] > newstate.tot)
								vol[newstate.jug[k]] = newstate.tot;
						if (visit[newstate.jug[0]][newstate.jug[1]][newstate.jug[2]] > newstate.tot || visit[newstate.jug[0]][newstate.jug[1]][newstate.jug[2]] == 0 && newstate.tot) {
							q.push(newstate);
							visit[newstate.jug[0]][newstate.jug[1]][newstate.jug[2]] = newstate.tot;
						}
					}
		}
		for (int i = D; i >= 0; i--)
			if (vol[i] != INFINTY) {
				printf("%d %d\n", vol[i], i);
				break;
			}
	}
	return 0;
}
