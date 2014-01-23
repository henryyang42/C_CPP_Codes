#include<stdio.h>
long long poww(int a, int p, int M){
    int i;
    long long aa = a, ans = 1;
    for(i = 0; i < 32; i++){
            if((p >> i) & 1)
                ans *= aa;
        ans %= M;
        aa = (aa * aa);
        aa %= M;
    }
    /*printf("%lld\n", ans);*/
    return ans;
}
int main(){
    int N, M, B, P, Q;
    while(scanf("%d%d%d%d", &B, &P, &Q, &M) > 0){
        printf("%lld piece(s) of cake left.\n", poww(poww(B, P, M), Q, M) % M);
    }
    return 0;
}
