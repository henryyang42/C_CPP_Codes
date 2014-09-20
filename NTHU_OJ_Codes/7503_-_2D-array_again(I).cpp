#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int s[1001][1001], ctt[1001][1001];
int hasodd(int n){
    int i;
    for(i = 1; i < 101;i++)
    if(i*i == n)
        return 1;
    return 0;
}
int main(){
    int n, q, i, j, ct = 0;
    while(scanf("%d%d", &n, &q) > 0, n + q){
        memset(ctt, 0, sizeof(ctt));
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++){
                    scanf("%d", &s[i][j]);
                if(hasodd(s[i][j]))
                    ctt[i][j] = ctt[i][j -1] + 1;
                else
                    ctt[i][j] = ctt[i][j -1] ;
            }

        printf("Case #%d:\n", ++ct);
        while(q--){
            int xa, xb, ya, yb, tot = 0;
            scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
            for(i = xa; i <= xb; i++)
                tot += ctt[i][yb] - ctt[i][ya - 1];
            printf("%d\n", tot);
        }
    }
    return 0;
}
