#include<stdio.h>
#include<string.h>
int main(){
    char s[10000];
    while(scanf("%s", s) > 0){
        int  i, ct = 0, l = strlen(s), fg = 0;
        for(i = 0; i < l; i++){
            if(s[i] == '(')
               ct++;
            if(s[i] == ')')
                ct--;
            if(ct < 0)
                fg = 1;
        }
        if(fg == 1 || ct){
            puts("Invalid");
            continue;
        }
        for(i = 0, ct = 0, fg = 0; i < l; i++){
            if(s[i] == '('){
               ct++;
               if(fg++)putchar(32);
               printf("%d", ct);
            }
            if(s[i] == ')')
                ct--;
        }
        putchar(10);
    }
    return 0;
}
