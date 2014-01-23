#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compare(const void *v, const void *o){
    return *(int*)v - *(int*)o;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, s[1000], x;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &s[i]);
        qsort(s, n, sizeof(int), compare);
        if(n % 2)
            x = s[(n - 1) / 2];
        else
            x = s[ n / 2 - 1];
        long long ans = 0;
        for(int i = 0; i < n; i++)
            ans += abs(s[i] - x);
        printf("%lld\n", ans);
    }
    return 0;
}

