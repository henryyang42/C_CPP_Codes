#include<stdio.h>
#define MAX 101
int main(){
    int i, j, testcase, A[MAX][MAX], B[MAX][MAX], n, m, p;
    while(scanf("%d", &testcase) > 0)
        while(testcase--){
            scanf("%d%d%d", &m, &n, &p);
            for(i = 0; i < m; i++)
                for(j = 0; j < n; j++)
                    scanf("%d", &A[i][j]);
            for(i = 0; i < n; i++)
                for(j = 0; j < p; j++)
                    scanf("%d", &B[i][j]);
            for(i = 0; i < m; i++, putchar(10))
                for(j = 0; j < p; j++){
                    int k, tot = 0;
                    for(k = 0; k < n; k++)
                        tot+=A[i][k]*B[k][j];
                    if(j)
                        putchar(32);
                    printf("%d", tot);
                }
            //if(testcase)
              putchar(10);
        }
    return 0;
}

