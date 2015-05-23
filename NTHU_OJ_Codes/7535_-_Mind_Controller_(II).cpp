#include<stdio.h>
void foo(int n){
    if(n <= 2){
        putchar(n + '0');
        return;
    }
    if(n % 3 == 0)
        foo(n / 3 - 1), foo(n / 3 + 1);
    else
        foo(n + 1);
}
int main(){
    int n;
    while(scanf("%d", &n) > 0)
        foo(n), putchar(10);
    return 0;
}
