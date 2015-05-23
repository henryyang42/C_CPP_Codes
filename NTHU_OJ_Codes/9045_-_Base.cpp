#include<stdio.h>
int main(){
    int n, t, k, top, s[100];
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        top = 0;
        while(n > 0)
            s[top++] = n % k, n /= k;
        while(--top >= 0)
            putchar('0' + s[top]);
        putchar(10);
    }
    return 0;
}
