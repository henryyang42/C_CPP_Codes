#include<stdio.h>

int main(){
    int n;
    while(scanf("%d", &n) > 0)
        if(n > 2 && n % 2 == 0)
            puts("YES");
        else
            puts("NO");
    return 0;
}
