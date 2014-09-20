#include<stdio.h>
long long poww(long long base, long long n, long long M){
    int i;
    long long ans = 1;
    for(i = 0; i < 32 ; i++){
            if((n >> i) & 1)
                ans *= base % M;
            ans %= M;
            base = base * base;
            base %= M;
    }
    return ans;
}
int main(){
    long long B, P, Q, M, ans, temp;
    while(scanf("%lld%lld%lld%lld", &B, &P, &Q, &M) > 0){
       long long int ct = 1, target = B % M, temp = (B*B)%M;
       while(B % M != temp % M)
            ct++, temp *= B, temp %= M;/*, printf("%lld ", temp);*/
       ans = poww(B, poww(P, Q, ct), M);
       /*printf("%target = %lld\n", ct);*/
        printf("%lld rope(s) left.\n", ans % M);
    }
	return 0;
}
