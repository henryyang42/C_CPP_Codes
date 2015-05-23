#include<stdio.h>
long long  pow2[33], powB[33];
int main(){
	int i, j, M, B, P, ans;
	for(pow2[0] = 1,i = 1; i < 33; i++)
		pow2[i] = pow2[i - 1] * 2;
	powB[0] = 1;
	while(scanf("%d %d %d", &B, &P, &M) > 0){
		for(powB[0] = B % M, i = 1; i < 33; i++)
			powB[i] = (powB[i - 1] * powB[ i - 1] )% M;
		for(ans = 1, i = 31; i >= 0; i--)
			if(P >= pow2[i])
				ans *= powB[i], ans %= M, P -= pow2[i];
		printf("%d\n",ans);
	}
    return 0;
}
