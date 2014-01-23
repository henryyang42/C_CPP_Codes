#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int d[105][105][5][2],s[105][105][5],in[105][105][5][2];
int op[5][2] = {{0,0},{-1,0},{0,1},{1,0},{0,-1}};

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int N,n,M,m,i,j,stx,sty,edx,edy,x,y,nx,ny,pre,px,py,cmd,cnt=1;
    int ii;
    while(scanf(" %d %d %d %d %d %d",&N,&M,&stx,&sty,&edx,&edy)==6 && (N+M+stx+sty+edx+edy)){
        memset(s,0,sizeof(s));
        stx--;    sty--;    edx--;    edy--;
        for(n=0;n<2*N-1;n++){
            x = n/2;
            if(n%2==0){
                for(m=0;m<M-1;m++){
                    scanf(" %d",&ii);
                    s[x][m][2] = s[x][m+1][4] = ii;
                }
            }
            else{
                for(m=0;m<M;m++){
                    scanf(" %d",&ii);
                    s[x][m][3] = s[x+1][m][1] = ii;
                }
            }
        }
        for(n=0;n<=N;n++)
            for(m=0;m<=M;m++)
                for(i=0;i<5;i++)
                    for(j=0;j<2;j++)
                        d[n][m][i][j] = 1e9;
        d[stx][sty][0][1] = 0;
        queue <int> q;
        q.push(stx);
        q.push(sty);
        q.push(0);
        q.push(1);
        memset(in,0,sizeof(in));
        int can = 0;
        int ans = 1e9;
        while(!q.empty()){
            x = q.front();    q.pop();
            y = q.front();    q.pop();
            pre = q.front();    q.pop();
            cmd = q.front();    q.pop();
            in[x][y][pre][cmd] = 0;
            if(x==edx && y==edy && cmd==1){
                can = 1;
                ans = min(ans,d[x][y][pre][cmd]);
            }
            for(i=1;i<5;i++){
                nx = x+op[i][0];
                ny = y+op[i][1];
                int pre_dir = (i+2)%4;
                if(nx>=0 && nx<N && ny>=0 && ny<M){  //沒有走出地圖外
                    if(s[x][y][i]!=0){  //這方向有路可走
                        long long add = s[x][y][i];
                        int mul = 0;
                        if(pre==0){
                            add = 2*s[x][y][i];
                            mul = 1;
                        }
                        if(i==pre || pre==0){  //沒轉彎
                            if(d[x][y][pre][cmd] + add < d[nx][ny][i][mul]){
                                d[nx][ny][i][mul] = d[x][y][pre][cmd] + add;
                                if(in[nx][ny][i][mul]==0){
                                    in[nx][ny][i][mul] = 1;
                                    q.push(nx);
                                    q.push(ny);
                                    q.push(i);
                                    q.push(mul);
                                }
                            }
                            if(nx==edx && ny==edy){
                                if(d[x][y][pre][cmd] + 2*s[x][y][i] < d[nx][ny][i][1]){
                                    d[nx][ny][i][1] = d[x][y][pre][cmd] + 2*s[x][y][i];
                                    if(in[nx][ny][i][1]==0){
                                        in[nx][ny][i][1] = 1;
                                        q.push(nx);
                                        q.push(ny);
                                        q.push(i);
                                        q.push(1);
                                    }
                                }
                            }
                        }
                        else{  //轉彎
                            add = 2*s[x][y][i];
                            mul = 1;
                            if(cmd==0){  //剛剛來的那條邊的長度要補
                                px = x-op[pre][0];
                                py = y-op[pre][1];
                                add += s[px][py][pre];
                            }
                            if(d[x][y][pre][cmd] + add < d[nx][ny][i][mul]){
                                d[nx][ny][i][mul] = d[x][y][pre][cmd] + add;
                                if(in[nx][ny][i][mul]==0){
                                    in[nx][ny][i][mul] = 1;
                                    q.push(nx);
                                    q.push(ny);
                                    q.push(i);
                                    q.push(mul);
                                }
                            }
                        }
                    }
                }
            }
        }
        if(can==1)
            printf("Case %d: %d\n",cnt++,ans);
        else
            printf("Case %d: Impossible\n",cnt++);
    }

    return 0;
}
