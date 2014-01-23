#include<stdio.h>
#include<string.h>
int mat[101][101], ans[101][101];
int di[] = {1, 1, 1, 0, 0,-1,-1,-1};
int dj[] = {1, 0,-1, 1,-1, 1, 0,-1};
int main(){
	int n, i, j, k;
	while(~scanf("%d",&n)){
		memset(ans,0,sizeof(ans));
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%d",&mat[i][j]);
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				for(k = 0; k < 8; k++)
					if(i + di[k] >=0 && i + di[k] < n && j + dj[k] >= 0 && j + dj[k] < n)
						ans[i][j] += mat[i + di[k]][j + dj[k]];
		for(i = 0; i < n; i++,putchar('\n'))
			for(j = 1, printf("%d",ans[i][0]); j < n; j++)
				printf(" %d",ans[i][j]);
	}
    return 0;
}
