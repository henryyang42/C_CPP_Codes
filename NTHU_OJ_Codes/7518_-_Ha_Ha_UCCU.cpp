#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char s[200001];
char word[20001][300] = {0};
int foo(int ct){
    int i, j;
    for(i = 0, j = ct - 1; i < j; i++, j--)
        if(strcmp(word[i], word[j]) != 0)
            return 0;
    return 1;
}
int main(){
    while(gets(s) > 0){
        int i, j, l = strlen(s), ct = 0;
        for(i = 0; i < l; i++){
            j = 0;
            if(isalpha(s[i])){
                while(isalpha(s[i]))
                    word[ct][j++] = s[i++];
                word[ct++][j++] = 0;
            }

        }
        /*printf("%d\n", ct);
        for(i = 0; i < ct; i++)
            puts(word[i]);
*/
        if(foo(ct) && ct)
            puts("YES");
        else
            puts("NO");
        memset(word, 0, sizeof(word));
    }
    return 0;
}
