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
    int N, M;
    while(scanf("%d%d", &N, &M) > 0){
        int i, a[1000], p[1000];
        long long tot = 0;
        for(i = 0; i < N; i++)
            scanf("%d", &a[i]);
        for(i = 0; i < N; i++)
            scanf("%d", &p[i]);
        for(i = 0; i < N; i++)
            tot += poww(a[i], p[i], M);
        printf("%lld piece(s) of cake left.\n", tot % M);
    }
    return 0;
}
