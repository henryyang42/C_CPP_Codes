#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
char s[N][N], ct[3][N][N], test[N][N];
int max = 3, fg, casect;
void dfs(int ii, int jj);

int main(){
    while(scanf("%d", &casect) > 0)while(casect--){
        int i, j, k;
        memset(ct, 0, sizeof(ct));
        for(i = 0; i < max*max; i++)
            for(j = 0; j < max*max; j++){
                scanf("%d", &s[i][j]);
                ct[0][i][s[i][j]] += 1;
                ct[1][j][s[i][j]] += 1;
                ct[2][(i/max)*max+ j/max][s[i][j]] += 1;
            }
        fg = 0;
        for(i = 0; i < max*max; i++)
            for(j = 0; j < max*max; j++)
                for(k = 1; k <= max*max; k++){
                if(ct[0][i][k] > 1)
                    fg = 3;
                if(ct[1][j][k] > 1)
                    fg = 3;
                if(ct[2][(i/max)*max+ j/max][k] > 1)
                    fg = 3;
            }
        if(fg == 3){
            puts("NO SOLUTION");
            continue;
        }
        memcpy(test, s, sizeof(s));
        dfs(0, 0);
        /*if(fg == 0)
            puts("NO SOLUTION");
        else*/
            printf("%d\n", fg);
    }
    return 0;
}
void dfs(int i, int j){
    if(i == max*max){
        fg += 1;
        int ii, jj;
      printf("%d\n", fg);
        for(ii = 0; ii < max *max; ii++, puts(""))
            for(jj = 0; jj < max *max ;jj++)
                printf("%d ", test[ii][jj]);
        puts("");
        getchar();
        return;
    }
    if(s[i][j]){
        dfs(i + (j + 1) / (max*max), (j + 1) % (max*max));
        return;
    }
    int k;
    for(k = 1; k <= max*max ; k++)
        if(ct[0][i][k] + ct[1][j][k] + ct[2][(i/max)*max+j/max][k]== 0){
            ct[0][i][k] = 1, ct[1][j][k] = 1, ct[2][(i/max)*max+j/max][k] = 1;
            test[i][j] = k;
            dfs(i + (j + 1) / (max*max), (j + 1) % (max*max));
            ct[0][i][k] = 0, ct[1][j][k] = 0, ct[2][(i/max)*max+j/max][k] = 0;
        }
}
