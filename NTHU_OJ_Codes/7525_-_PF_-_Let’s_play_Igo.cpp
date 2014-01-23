#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char map[1011][1011];
int B[1010][1010], W[1010][1010];
int findW(int xa, int ya, int xb, int yb){
    return W[xb][yb] - W[xb][ya-1] - W[xa - 1][yb] + W[xa - 1][ya -1];
}
int findB(int xa, int ya, int xb, int yb){
	return B[xb][yb] - B[xb][ya-1] - B[xa - 1][yb] + B[xa - 1][ya -1];
}
int main(){
    int m, n, q, casect = 0;
    while(scanf("%d%d%d", &m, &n, &q) > 0, m+n+q){
        int i, j;
        memset(map, 0, sizeof(map));
        memset(B, 0, sizeof(B));
        memset(W, 0, sizeof(W));
        for(i = 0; i < m; i++)
        	scanf("%s", map[i+1] + 1);
        for(i = 1; i <= m; i++)
        	for(j = 1; j <= n; j++){
                    B[i][j] = B[i][j - 1] + (map[i][j] == 'B');
                    W[i][j] = W[i][j - 1] + (map[i][j] == 'W');
        	}
        for(i = 1; i <= m; i++)
        	for(j = 1; j <= n; j++){
				B[i][j] += B[i-1][j];
				W[i][j] += W[i-1][j];
			}
        long long int Wct = 0, Bct = 0;
        for(i = 0; i < q; i++){
        	int xa, ya, xb, yb, temp;
            scanf("%d%d%d%d", &xa, &ya, &xb,&yb);
            if(xa > xb)
                temp = xa, xa = xb, xb = temp;
            if(ya > yb)
               	temp = ya, ya = yb, yb = temp;
        	Wct += findW(xa,  ya,  xb, yb);
            Bct += findB(xa,  ya,  xb, yb);
        }
        printf("Case #%d:\n", ++casect);
        printf("Redline: %lldpts Cake: %lldpts\n", Bct, Wct);
        if(Bct == Wct)
            puts("Tie!");
        if(Bct > Wct)
            puts("Redline wins!");
        if(Bct < Wct)
            puts("Cake wins!");
    }
	return 0;
}
