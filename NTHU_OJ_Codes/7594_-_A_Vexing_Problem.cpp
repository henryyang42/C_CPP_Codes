#include<stdio.h>
#include<queue>
#include<map>
#include<ctype.h>
using namespace std;
int n, m, d[4][2] = {{0, 1}, {0,-1}, {1, 0}, {-1, 0}}, sz, dir[] = {1,-1}, goal;
struct State{
	char s[10][10];
	int mv;
	bool operator < (const State &x) const{
		for(int i = 0; i < n-1; i++)
			for(int j = 1; j < m-1; j++)
				if(s[i][j] != x.s[i][j])
					return s[i][j] < x.s[i][j];
		return false;
	}
}E, G;
struct Edge{
	int i, j;
	char op, x;
	State pre;
}edge;
Edge makeEdge(int _i, int _j, char _op, char _x, State _pre){
	edge.i = _i, edge.j = _j, edge.op = _op, edge.x = _x, edge.pre = _pre;
	return edge;
}
map<State, Edge> M;
vector<Edge>v;
void trackback(State x){
	if(x.mv == 0)
		return;
	trackback(M[x].pre);
	v.push_back(M[x]);
}
void fall(char s[10][10]){
    for(int i = n - 1; i >= 0; i--){
        for(int j = 1; j < m - 1; j++){
            if(isalpha(s[i][j])){
                int k = i+1;
                while(k < n && s[k][j]=='-'){
                    s[k][j] = s[k-1][j];
                    s[k-1][j] = '-';
                    k++;
                }
            }
        }
    }
}
void dfs(int i, int j, char s[10][10], char c){
	for(int k = 0; k < 4; k++){
		int ii = i+d[k][0], jj = j+d[k][1];
		if(ii < n && jj < m - 1 && ii > 0 && jj > 0 && s[ii][jj] == c){
			s[ii][jj] = '-';
			dfs(ii, jj, s, c);
			sz++;
		}
	}
}
int isGoal(char s[10][10]){
	int tot = 0;
	for(int i = 0; i < n - 1; i++)
		for(int j = 1; j < m - 1; j++)
			if(isalpha(s[i][j]))
				return 1;
	return 0;
}
int delete_able(char s[10][10]){
	int fg = 0;
	for(int i = 0; i < n - 1; i++)
		for(int j = 1; j < m - 1; j++)if(isalpha(s[i][j])){
			sz = 0;
			dfs(i, j, s, s[i][j]);
			if(sz){
				s[i][j] = '-';
				fg = 1;
			}
		}
	return fg;
}
int main(){
	char casename[1000];
	while(scanf(" %d%d%s", &n, &m, casename), n + m){
		M.clear();
		int id = 1;
		for(int i = 0; i < n; i++)
			scanf("%s", E.s[i]);
		goal = E.mv = 0;
		M[E] = edge;
		queue<State> Q;
		Q.push(E);
		while(!Q.empty() && !goal){
			State now = Q.front();
			Q.pop();
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					if(isalpha(now.s[i][j])){
						char tmp;
						for(int k = 0; k < 2; k++)
							if(j + dir[k] < m && now.s[i][j+dir[k]] == '-'){
								State next = now;
								next.mv = now.mv+1;
								tmp = next.s[i][j], next.s[i][j] = next.s[i][j+dir[k]], next.s[i][j+dir[k]] = tmp;
								do{
									fall(next.s);
								}while(delete_able(next.s));
								if(M.find(next) == M.end()){
									M[next] = makeEdge(i, j, dir[k] == 1 ? 'R' : 'L', now.s[i][j], now);
									Q.push(next);
									if(isGoal(next.s) == 0){
										G = next;
										goal = 1;
										break;
									}
								}
							}
					}
		}
		printf("%s: Minimum solution length = %d\n", casename, G.mv);
		v.clear();
		trackback(G);
		for(int i = 0; i < v.size(); i++){
			printf("(%c,%d,%d,%c)", v[i].x, v[i].i, v[i].j, v[i].op);
			putchar(i == v.size() - 1 ? 10 : (i % 4 == 3 ? 10 : 32));
		}
	}
	return 0;
}
