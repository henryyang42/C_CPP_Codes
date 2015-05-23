#include<stdio.h>
#include<string.h>
bool Map[3001][3001] = {0};
int mx[3000];
int my[3000];
int findmouse(int x, int y){
    int tot = 0;
    int dx[] = {1, 1, -1, -1};
    int dy[] = {-1,1,1,-1};
    for(int i = 0; i <= 10; i++)
        for(int j = 0; j <= 10; j++)
            if(i + j <= 10){
                for(int k = 0; k < 4; k++)
                if(x + dx[k] *i >= 1 && x +dx[k] * i <= 3000 && y + dy[k] *j >= 1 && y + dy[k] *j <= 3000)
                    if(Map[x + dx[k] *i][y + dy[k] *j])return 1;
            }
            return 0;
}
int main(){
    int M, H, i, x, y, ans;
    while(scanf("%d%d", &M, &H) > 0){
        memset(Map, 0, sizeof(Map));
        for(i = 0; i < M; i++)
            scanf("%d%d", &mx[i], &my[i]);
        for(i = 0; i < H; i++)
            scanf("%d%d", &x, &y), Map[x][y] = 1;
        for(i = 0, ans = 0; i < M; i++)
            ans += findmouse(mx[i], my[i]);
        printf("%d\n", ans);
    }
    return 0;
}
