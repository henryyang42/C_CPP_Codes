#include<stdio.h>
int main(){
    int n, m, k;
    while(scanf("%d%d", &m, &n) > 0){
        int ct[10000] = {0}, fg = 0;
        k = m-n;
        for(int i = m; i > 1; i--){
            int temp = i;
            for(int j = 2; temp > 1; j++)
                while(temp % j == 0)
                    ct[j]++, temp /= j;
        }
        for(int i = n; i > 1; i--){
            int temp = i;
            for(int j = 2; temp > 1; j++)
                while(temp % j == 0)
                    ct[j]--, temp /= j;
        }
        for(int i = k; i > 1; i--){
            int temp = i;
            for(int j = 2; temp > 1; j++)
                while(temp % j == 0)
                    ct[j]--, temp /= j;
        }
        for(int i = 2; i < 10000; i++)
            if(ct[i]){
                if(fg++)
                    putchar('*');
                if(ct[i] > 1)
                    printf("%d^%d", i, ct[i]);
                else
                    printf("%d", i);
            }
        if(fg == 0)
            putchar('1');
        putchar(10);
    }
    return 0;
}
