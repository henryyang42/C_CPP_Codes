#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
#define MAX 1000000000000000LL
using namespace std;
int n, ct;
int main(){
    while(cin >> n, n >= 0){
        int adj[128][128] = {}, st, ed, in[128] = {}, path[128] = {};
        long long dis[128], item;
        char aa[10], bb[10];
        while(n--){
            cin >> aa >> bb;
            adj[aa[0]][bb[0]] = adj[bb[0]][aa[0]] = 1;
        }
        for(int i = 0; i < 128; i++)
            dis[i] = MAX;
        cin >> item >> aa >> bb;
        st = bb[0], ed = aa[0];
        dis[st] = item;
        queue<int>Q;
        Q.push(st);
        while(!Q.empty()){
            int x = Q.front(); Q.pop();
            in[x] = 0;
            for(int y = 0; y < 128; y++){
                if(adj[x][y]){
                    long long len = 0, temp = dis[x];
                    if(islower(x))
                        len = 1;
                    else{
                        len = MAX;
                         if(dis[x]%19==0)
                            len =  dis[x]*20/19 - dis[x];
                        else
                            len = (dis[x]*20/19 + 1) - dis[x];
                    }
 
                    if(dis[x] + len < dis[y]){
                        dis[y] = dis[x] + len;
                        path[y] = x;
                        if(!in[y])
                            Q.push(y), in[y] = 1;
                    }
                    else if(dis[x] + len == dis[y] && path[y] > x){
                        path[y] = x;
                    }
                }
            }
        }
        printf("Case %d:\n", ++ct);
        printf("%lld\n", dis[ed]);
        vector<int>gg;
        for(int i = ed; i !=st; i=path[i])
            printf("%c-", i);
        printf("%c", st);
        putchar(10);
    }
    return 0;
}