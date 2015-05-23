#include <cstdio>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
struct edge {
    int to;
    char op, num;
} E;
map<int, edge> M;
int len;
char path[1000];
void V(char puzzle[3][3], int k) {
    int temp = puzzle[2][k];
    puzzle[2][k] = puzzle[1][k], puzzle[1][k] = puzzle[0][k], puzzle[0][k] = temp;
}
void H(char puzzle[3][3], int k) {
    int temp = puzzle[k][0];
    puzzle[k][0] = puzzle[k][1], puzzle[k][1] = puzzle[k][2], puzzle[k][2] = temp;
}
int toint(char puzzle[3][3]) {
    int state = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            state = state * 10 + puzzle[i][j];
    return state;
}
void toarray(char puzzle[3][3], int state) {
    for (int i = 2; i >= 0; i--)
        for (int j = 2; j >= 0; j--)
            puzzle[i][j] = state % 10, state /= 10;
}
void findpath(int state) {
    if (state == 123456789) {
        path[len] = 0;
        return;
    }
    edge e = M[state];
    path[len] = e.op;
    path[len + 1] = e.num;
    len += 2;
    findpath(e.to);
}

int main() {
    int state = 123456789;
    queue<int> Q;
    Q.push(state);
    while (!Q.empty()) {
        state = Q.front();
        Q.pop();
        for (int i = 0; i < 3; i++) {
            char temp[3][3];
            int now;
            toarray(temp, state);
            V(temp, i);
            now = toint(temp);
            if (M.find(now) == M.end()) {
                E.to = state, E.op = 'V', E.num = '1' + i;
                M[now] = E;
                Q.push(now);
            }
            toarray(temp, state);
            H(temp, i);
            now = toint(temp);
            if (M.find(now) == M.end()) {
                E.to = state, E.op = 'H', E.num = '1' + i;
                M[now] = E;
                Q.push(now);
            }
        }
    }
    int x;
    while (scanf("%d", &x) > 0, x) {
        int r = x;
        for (int i = 0; i < 8; i++)
            scanf("%d", &x), r = r * 10 + x;
        if (M.find(r) == M.end())
            puts("Not solvable");
        else {
            len = 0;
            findpath(r);
            if (len)
                printf("%d %s\n", len / 2, path);
            else
                puts("0");
        }

    }
    return 0;
}

