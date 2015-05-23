#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
int adj[20][20], in[20], out[20];
vector<int> gg, ans;
void dfs(int x){
    for(int i = 0; i < 10; i++)
        if(adj[x][i]){
            adj[x][i]--;
            dfs(i);
            ans.push_back(i);
        }
}
int main(){
    int a, b, st;
    while(cin >> a >> b){
        if(a==b){
            printf("%d\n", a);
            continue;
        }
        memset(adj, 0, sizeof(adj));
        memset(out, 0, sizeof(out));
        memset(in, 0, sizeof(in));
        gg.clear();
        ans.clear();
        while(a < 10 && a <= b)
            gg.push_back(a++);
        for(int i = a; i <= b; i++){
            adj[i/10][i%10]++;
            in[i%10]++;
            out[i/10]++;
        }
        int x = 0, ct[20] = {};
        for(int i = 0; i < 10; i++)
            if(in[i] > out[i])
                x += in[i] - out[i];
        for(int i = 0; i < 10; i++)
            while(in[i] > out[i] && x > 1)
                for(int j = 0; j < 10; j++)
                    if(in[j] < out[j]){
                        out[i]++;
                        in[j]++;
                        adj[i][j]++;
                        x--;
                        break;
                    }
        st = -1;
        for(int i = 0; i < 10; i++)
            if(in[i] < out[i])
                st = i;
        if(st != -1){
            dfs(st);
            putchar('0'+st);
            ct[st]++;
        }
        for(int i = ans.size()-1; i >= 0; i--)
            putchar('0' + ans[i]), ct[ans[i]]++;
        for(int i = 0; i < gg.size(); i++)
            if(!ct[gg[i]])
                putchar('0'+gg[i]);
        putchar(10);

    }
    return 0;
}