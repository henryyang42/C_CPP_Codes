#include<stdio.h>
#include<string.h>
char s[1000];
int main(){
    while(scanf("%s", s) > 0){
        int s1[1000] = {0}, s2[1000] = {0}, ans[1000] = {0}, l =  strlen(s), i, j;
        for(  i = 0; i < l; i++)
            s1[i] = s2[i] = s[l - i - 1] - 48;
        s1[0] ++;
        for(i = 0; i < 500; i++)
            for(j = 0; j < 500; j++)
                ans[i+j] += s1[i] * s2[j];
        for(i = 0; i < 1000 - 1; i++)
            ans[i + 1] += ans[i] / 10, ans[i] %= 10;
        i = 1000 - 1;
        while(ans[i] == 0)
            i--;
        if(i < 0)
            puts("0");
        else{
            while(i >= 0)
                putchar(ans[i--] + 48);
            putchar(10);
        }
    }
    return 0;
}
