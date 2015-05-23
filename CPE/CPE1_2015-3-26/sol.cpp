#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char buffer[101], Len, s[101], K, ASCII[1000] = {0};
void dfs(int depth, int start){
    int i;
    if(depth == K){
        buffer[K] = 0;
        puts(buffer);
        return;
    }
    for(i = start; i < Len; i++)
        if(s[i] != buffer[depth])
            buffer[depth] = s[i], dfs(depth + 1, i + 1);
    buffer[depth] = 0;
}

int main(){
    int t, i, l;
    scanf("%d", &t);
    while(t--){
        memset(s, 0, sizeof(s));
        memset(buffer, 0, sizeof(buffer));
        memset(ASCII, 0, sizeof(ASCII));
        scanf("%s %d", s, &K);
        l = strlen(s);
        if(l > 100)
            while(1);
        for(i = 0; i < l; i++){
            ASCII[s[i]]++;
            if(s[i] > 'K')
                while(1);
        }

        for(i = 'A', Len = 0; i <= 'K'; i++){
            if(ASCII[i] > K)
                ASCII[i] = K;
            while(ASCII[i])
                s[Len++] = i, ASCII[i]--;
        }
        s[Len] = 0;
        dfs(0, 0);
        putchar(10);
    }
    return 0;
}
