#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int s[1001][1001], ctt[1001][1001];
char prime[1001] = {0};
int hasprime(int n){
    return  !prime[n];
}
int main(){
    int n, q, i, j, ct = 0;
    for(i = 2, prime[1] = 1, prime[0] = 1; i < 1001; i++)
    	if(!prime[i])
    		for(j = i * 2; j < 1001; j += i)
    			prime[j] = 1;
    while(scanf("%d%d", &n, &q) > 0, n + q){
        memset(ctt, 0, sizeof(ctt));
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++){
                    scanf("%d", &s[i][j]);
                if(hasprime(s[i][j]))
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
