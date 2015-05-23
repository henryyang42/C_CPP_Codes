#include<stdio.h>
#include<string.h>
char s[1000002];
int main(){
    int t, mod, k, l, i;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%s", &mod, &k, s);
        l = strlen(s);
        k %= 26;
        if(mod == 1){
            for(i = l - 1; i >= 0; i--)
                putchar('A' + (s[i] - 'A' + k) % 26);
        }
        else{
             for(i = l - 1; i >= 0; i--)
                putchar('A' + (s[i] - 'A' - k + 26) % 26);
        }
        putchar(10);
    }
    return 0;
}
