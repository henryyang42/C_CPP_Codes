#include<stdio.h>
void foo(int n){
    if(n <= 3){
        putchar(n + '0');
        return;
    }
    if(n % 2 == 0)
        foo(n / 2 - 1), foo(n / 2 + 1);
    else
        foo((n - 1) / 2), foo((n + 1) / 2);
}
int main(){
    int n;
    while(scanf("%d", &n) > 0)
        foo(n), putchar(10);
    return 0;
}
