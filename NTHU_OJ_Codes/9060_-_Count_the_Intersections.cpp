#include<stdio.h>
int ans[1000003];
int main(){
    int n;
    for(int i = 2; i <= 1000000; i++)
        ans[i] = (ans[i-1] + i-1) % 10000;
    while(scanf("%d", &n), n)
        printf("%d\n", ans[n] % 10000);
    return 0;
}
