#include<stdio.h>
#include<string.h>
struct good{
    int ori, act;
}s[100];
int adj[100][100], in[100];
int n, kind, bargain;
void dfs(int x){
    for(int i = 1; i <= n; i++)
        if(adj[x][i] != -1){
            if(s[i].act > s[x].act + adj[x][i])
                s[i].act = s[x].act + adj[x][i];
            dfs(i);
        }
}
void same(){
    for(int p = 1; p <= 30; p++){
        int minp = 100;
        for(int i = 1; i <= n; i++)
            if(s[i].ori == p)
                minp = s[i].act < minp ? s[i].act : minp;
        for(int i = 1; i <= n; i++)
            if(s[i].ori == p)
                s[i].act = minp;
    }
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){

        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &kind);
            scanf("%d", &s[kind].ori);
            s[kind].act = s[kind].ori-1;
        }
        scanf("%d", &bargain);
        memset(adj, -1, sizeof(adj));
        memset(in, 0, sizeof(in));
        while(bargain--){
            int n1, n2, some;
            scanf("%d%d%d", &n1, &n2, &some);
            adj[n1][n2] = some;
            in[n2] = 1;
        }
        same();
        for(int i = 1; i <= n; i++){
            if(in[i] == 0)
                dfs(i);
            same();
        }
        same();
        for(int i = 1; i <= n; i++){
            if(in[i] == 0)
                dfs(i);
            same();
        }
        for(int i = 1; i <= n; i++)
            printf("%d %d\n", i, s[i].act);
        int ct = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++)
                for(int k = j+1; k <= n; k++)
                    if(i != j && k != i && s[i].act == s[j].act + s[k].act){
                        ct++;
                        j = k = n+1;
                    }
        }
        printf("%d\n", ct);
    }
    return 0;
}

