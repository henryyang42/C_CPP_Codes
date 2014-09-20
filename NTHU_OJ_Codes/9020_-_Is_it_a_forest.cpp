#include<stdio.h>
int s[1000001];
int p(int x){
    return x == s[x] ? x : (s[x] = p(s[x]));
}
int main(){
    int fg, a, b, n, q;
    while(scanf("%d%d", &n, &q), n+q){
        for(int i = 0; i <= n; i++)
            s[i] = i;
        fg = 1;
        while(q--){
            scanf("%d%d", &a, &b);
            if(p(a) == p(b))
                fg = 0;
            else
                s[p(b)] = p(a);
        }
        if(fg)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
