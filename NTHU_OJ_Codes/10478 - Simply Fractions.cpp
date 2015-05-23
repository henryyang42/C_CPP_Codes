#include<stdio.h>
long long gcd(long long a, long long b){
    while(a > 0 && b > 0)
        if(a > b)
            a %= b;
        else
            b %= a;
    return a + b;
}
long long a, b, c, d, e, f, g;
int main(){
    int t;
    while(scanf("%d", &t) > 0){
        scanf("%lld%lld", &a, &b);
        t--;
        while(t--){
            scanf("%lld%lld", &c, &d);
            e = a*d + b*c;
            f = b*d;
            g = gcd(e, f);
            a = e/g;
            b = f/g;
        }
        printf("%lld/%lld\n", a, b);
    }
    return 0;
}
