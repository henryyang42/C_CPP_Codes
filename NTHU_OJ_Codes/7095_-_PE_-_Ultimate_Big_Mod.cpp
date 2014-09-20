#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int mat[100][100], A[100], c[100], F[100];

void times(long long int mat[100][100], long long int A[100], int n, int M){
	long long int temp[100] = {0};
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
		temp[i] += (mat[i][j] % M) * (A[j] % M), temp[i] %= M;
	memcpy(A, temp, sizeof(temp));
}

void square(long long int mat[100][100], int n, int M){
	long long int temp[100][100] = {0};
	int i, j, k;
	for(i = 0; i < n; i++)
		for(j = 0; j < n ;j++)
			for(k = 0; k < n; k++)
				temp[i][j] += (mat[i][k] % M) * (mat[k][j] % M), temp[i][j] %= M;
	memcpy(mat, temp, sizeof(temp));	
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int k, n, M, i;
		memset(mat, 0, sizeof(mat));
		scanf("%d%d%d", &k, &M, &n);
		for(i = 0; i <= k; i++)
			scanf("%lld", &c[i]);
		for(i = 0; i < k; i++)
			scanf("%lld", &F[i]);
		for(i = 0, A[k] = c[k], mat[0][k] = 1, mat[k][k] = 1; i < k; i++)
			A[i] = F[k - i - 1], mat[0][i] = c[i];
		for(i = 1; i < k; i++)
			mat[i][i - 1] = 1;
		for(i = 0; n >> i; i++){
			if((n >> i) & 1)
				times(mat, A, k + 1, M);
			square(mat, k + 1, M);
		}
		if(k)
			printf("%lld\n", A[k - 1]);
		else
			printf("%lld\n", A[0]);
	}
	return 0;	
}
