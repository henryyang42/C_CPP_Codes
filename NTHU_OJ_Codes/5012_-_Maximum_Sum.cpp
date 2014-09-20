#include<stdio.h>
#include<string.h>
int s[101][101];
int sum[101][101];
int square_area(int i, int j, int k, int l){
	int tot = 0, ii, jj;
	for(ii = i; ii <= k; ii++)
		tot += sum[ii][l] - sum[ii][j - 1];
	return tot;
}
int main(){
	int n;
	while(scanf("%d", &n) > 0){
		int i, j, k, l, max = -99999999;
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				scanf("%d", &s[i][j]);
		memset(sum, 0, sizeof(sum));
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				sum[i][j] = sum[i][j - 1] + s[i][j];
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				for(k = i; k <= n; k++)
					for(l = j; l <= n; l++){
						int temp = square_area(i, j, k, l);
						if(max < temp)
							max = temp;
					}
		printf("%d\n", max);	
	}
	return 0;
}
