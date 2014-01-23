#include<stdio.h>
#define N 10
int det(int matrix[N][N], int n){
	int i, j, k, tot = 0, sig, temp[N][N] = {0}, offset;
	if(n == 2)
		return matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1];
	for(i = 0, sig = 1; i < n; i++, sig*=-1){
		for(j = 0, offset = 0; j < n; j++){
			if(j == i){
				offset = -1;
				continue;
			}
			for(k = 1; k < n; k++)
				temp[j + offset][k - 1] = matrix[j][k];
		}
		tot += (sig*matrix[i][0]*det(temp, n - 1));	
	}
	return tot;	
}
int main(){
	int i, j, n, t;
	while(scanf("%d", &t) > 0)
	while(t--){
		scanf("%d", &n);
		int s[N][N] = {0};
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%d", &s[i][j]);
		printf("%d\n", det(s, n));
	}
    return 0;
}
