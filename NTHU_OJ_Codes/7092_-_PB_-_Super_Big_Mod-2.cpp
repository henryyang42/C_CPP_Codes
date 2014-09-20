#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int mat[2][2], standard[2][2] = {{1, 1}, {1, 0}}, ans[2][2];
void square(long long int mat[2][2], int M){
	long long int temp[2][2];
	temp[0][0] = mat[0][0] * mat[0][0] + mat[0][1] * mat[1][0], temp[0][0] %= M;
	temp[0][1] = mat[0][0] * mat[0][1] + mat[0][1] * mat[1][1], temp[0][1] %= M;
	temp[1][0] = mat[0][0] * mat[1][0] + mat[1][1] * mat[1][0], temp[1][0] %= M;	
	temp[1][1] = mat[1][0] * mat[0][1] + mat[1][1] * mat[1][1], temp[1][1] %= M;
	memcpy(mat, temp, sizeof(temp));
}
void times(long long int fib[2], long long int mat[2][2], int M){
	long long int temp[2];
	temp[0] = mat[0][0] * fib[0] + mat[0][1] * fib[1], temp[0] %= M;
	temp[1] = mat[1][0] * fib[0] + mat[1][1] * fib[1], temp[1] %= M;
	memcpy(fib, temp, sizeof(temp));
}
int main(){
	int n, M, i, t, k, x;
	while(scanf("%d%d", &n, &M) > 0){
		memcpy(mat, standard, sizeof(standard));
		long long int fib[2] = {0, 1};
		for(i = 0; n >> i; i++){
			if((n >> i) & 1)
				times(fib, mat, 1 << M);
			square(mat, 1 << M);
		}
		printf("%lld\n", fib[0]);
	}
	return 0;
}
