#include <cstdio>
int n, m, ma;
char s[123][123];
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
void dfs(int x, int y){
    ma++;
    s[x][y] = 0;
    for(int k = 0; k < 4; k++){
        int ii = x + di[k];
        int jj = y + dj[k];
        if(ii >= 0 && ii < n && jj >= 0 && jj < m && s[ii][jj] == '#')
            dfs(ii, jj);
    }
}
int main(){
    while(scanf("%d%d", &n, &m), n+m){
        for(int i = 0; i < n; i++)
            scanf("%s", s[i]);
        int Max = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(s[i][j] == '#'){
                    ma = 0;
                    dfs(i, j);
                    Max = ma > Max ? ma : Max;
                }
        printf("%d\n", Max);
    }
    return 0;
}

