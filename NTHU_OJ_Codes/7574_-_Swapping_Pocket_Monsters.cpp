#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, s[100];
        int ans = 0;
        scanf("%d", &n);
        for(int i = 0; i < 2 * n; i++)
            scanf("%d", &s[i]);
        for(int i = 0; i < 2 * n; i+= 2){
            if(s[i] == s[i+1]) continue;
            for(int j = i + 1; j < 2 * n; j++)
                if(s[j] == s[i]){
                    for(int k = j; k > i + 1; k--){
                        int temp = s[k];
                        s[k] = s[k - 1];
                        s[k - 1] = temp;
                        ans++;
                    }
                    break;
                }
        }
        printf("%d\n", ans);
    }
    return 0;
}

