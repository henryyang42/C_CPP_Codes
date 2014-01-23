#include<queue>
#include<stdio.h>
#include<string.h>
#define INFINTY 10000
using namespace std;
int Jug[3], D;
char visit[201][201][201];
int vol[1000];
struct state{
	int jug[3], tot;
};
state move(state x, int i, int j){
	//move from i to j
	if(x.jug[i] == 0 || x.jug[j] == Jug[j])
		return x;
	x.jug[j] += x.jug[i];
	x.tot += x.jug[i];
	x.jug[i] = 0;
	if(x.jug[j] > Jug[j])
		x.jug[i] = x.jug[j] - Jug[j], x.jug[j] = Jug[j], x.tot -= x.jug[i];
	return x;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		memset(visit, 0, sizeof(visit));
		for(int i = 1; i < 1000; i++)
			vol[i] = INFINTY;
		scanf("%d%d%d%d", &Jug[0], &Jug[1], &Jug[2], &D);
		state original = {0, 0, Jug[2], 0}, temp;
		queue<state> q;
		q.push(original);
		while(!q.empty() && vol[D] == INFINTY){
			temp = q.front();
			q.pop();
			for(int i = 0; i < 3; i++)
				if(vol[temp.jug[i]] > temp.tot)
					vol[temp.jug[i]] = temp.tot;
			for(int i = 0; i < 3; i++)
				for(int j = 0; j < 3; j++)
					if(i != j){
					state newstate = move(temp, i, j);
					if(!visit[newstate.jug[0]][newstate.jug[1]][newstate.jug[2]])
						q.push(newstate);
					visit[newstate.jug[0]][newstate.jug[1]][newstate.jug[2]] = 1;
				}
		}
		if(vol[D] != INFINTY)
			printf("%d %d\n", vol[D], D);
		else{
			for(int i = D - 1; i >= 0; i--)
				if(vol[i] < INFINTY){
					printf("%d %d\n", vol[i], i);
					break;
				}
		}
	}
	return 0;
}
