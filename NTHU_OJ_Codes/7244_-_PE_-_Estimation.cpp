#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long  s[100000];
int main(){
    s[0] = 0, s[1] = 1;
    for(int i = 2; i <= 13; i++)
        s[i] = (s[i - 1] * (4 * i - 2) / (i + 1)) % 1573921;
    for(int i = 14; i < 50001; i++){
        long long x, min = 1000000000000000000LL;
        for(int j = 1; j <= 10; j++)
            x = (j * s[i - j] * s[i - (10 - j + 1)]) % 1573921, min = x < min ? x : min;
        s[i] = min;
    }
    int n;
    while(scanf("%d", &n) > 0)
        printf("%lld\n", n > 0 ? s[n] : 0);
    return 0;
}

