#include<stdio.h>
bool m[100001];
int parent[100001];
int LCA(int x, int y){
    if(x == y || x == parent[y])
        return x;
    if(y == parent[x])
        return y;
    if(parent[x] != -1)
        return LCA(y, parent[x]);
    if(parent[y] != -1)
        return LCA(x, parent[y]);
}
int main(){
    int t, n, q ,x, a, b, ct = 0;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &x), parent[i] = x;
        printf("Case %d:", ++ct);
        while(scanf("%d%d", &a, &b), a+b){
            while(a != -1)
                m[a] = 1, a = parent[a];
            while(!m[b])
                b = parent[b];
            printf(" %d", b);
            for(int i = 1; i <= n; i++) m[i] = 0;
        }
        putchar(10);
    }
    return 0;
}
