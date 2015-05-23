#include<stdio.h>
int parent[1001], height[1001];
int a, b, t, n, x, ct = 0;
void dfs(int x){
    for(int i = 1; i <= n; i++)
        if(parent[i] == x)
            height[i] = height[x] + 1, dfs(i);
}
int lca(int a, int b){
    bool rec[1001] = {};
    while(a != -1)
        rec[a] = 1, a = parent[a];
    while(!rec[b])
        b = parent[b];
    return b;
}
int main(){
    while(scanf("%d", &n) > 0){
        for(int i = 1; i <= n; i++)
            scanf("%d", &parent[i]);
        for(int i = 1; i <= n; i++)
            if(parent[i] == -1)
                height[i] = 0, dfs(i);
        printf("Case %d:", ++ct);
        while(scanf("%d%d", &a, &b), a+b)
            printf(" %d", height[a] + height[b] - 2*height[lca(a, b)]);
        putchar(10);
    }
    return 0;
}
