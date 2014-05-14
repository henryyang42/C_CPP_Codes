#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int adj[50][2000], st, in[2000], visit[2000], fg, start, inct;
vector<int> ans;
void add_(int a, int b, int c){
    adj[a][c] = b;
    adj[b][c] = a;
    in[a]++;
    in[b]++;
    st++;
}
void dfs(int x){
    for(int i = 0; i < 2000; i++)
        if(adj[x][i] && !visit[i]){
            visit[i] = 1;
            dfs(adj[x][i]);
            ans.push_back(i);
        }
}
int main(){
    int a, b, c;
    while(cin >> a >> b, a+b){
        memset(adj, 0, sizeof(adj));
        memset(in, 0, sizeof(in));
        memset(visit, 0, sizeof(visit));
        ans.clear();
        inct = st = 0;
        cin >> c;
        start = min(a, b);
        add_(a, b, c);
        while(cin >> a >> b, a+b){
            cin >> c;
            add_(a, b, c);
        }
        for(int i = 0; i < 2000; i++)
            inct += in[i] % 2;
        if(inct == 0){
            dfs(start);
            if(ans.size() == st){
                printf("%d", ans[st-1]);
                for(int i = st-2; i >= 0; i--)
                    printf(" %d", ans[i]);
                putchar(10);
            }
            else
                puts("Round trip does not exist.");    
        }
        else
            puts("Round trip does not exist.");
        putchar(10);
    }
    return 0;
}