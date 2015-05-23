#include<stdio.h>
long long digit[40] = {0, 10, 9};
int main(){
    int n, i, j;
    for(i = 3; i < 30; i+= 2)
        digit[i] = digit[i+1] = digit[i-1]*10;
    while(scanf("%d", &n) > 0){
        if(n <= 10){
            printf("%d\n", n-1);
            continue;
        }
        i = 1;
        while(n > digit[i])
            n -= digit[i++];
        char ans[100] = {0};
        for(n--, ans[0] = 1, j = (i+1) / 2 - 1; j >= 0; j--)
            ans[j] += n % 10, n /= 10;
        if(i % 2){
            for(j = 0; j < (i+1) / 2; j++)
                putchar('0' + ans[j]);
            for(j = (i+1) / 2 - 2; j >= 0 ; j--)
                putchar('0' + ans[j]);
        }
        else{
             for(j = 0; j < (i+1) / 2; j++)
                putchar('0' + ans[j]);
            for(j = (i+1) / 2 - 1; j >= 0 ; j--)
                putchar('0' + ans[j]);
        }
        putchar(10);
    }
    return 0;
}
