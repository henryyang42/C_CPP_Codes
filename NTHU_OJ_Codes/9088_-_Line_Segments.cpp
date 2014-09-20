#include<stdio.h>
#include<stdlib.h>
int max(int a, int b){
    return a > b ? a : b;
}
int min(int a, int b){
    return a < b ? a : b;
}
int s[1000002][2];
int compare(const void *v, const void *o){
    int *p1 = (int*)v, *p2 = (int*)o;
    if(*p1 == *p2)
        return *(p1+1) - *(p2+1);
    return *p1 - *p2;
}
int main(){
    int n, ans, i;
    while(scanf("%d", &n), n){
        for(i = 0; i < n; i++)
            scanf("%d%d", &s[i][0], &s[i][1]);
        qsort(s, n, sizeof(s[1]), compare);
        for(i = 1, ans = 0; i <= n; i++){
            int xmin = s[i-1][0], xmax = s[i-1][1];
            while(s[i][0] <= xmax && s[i][0] >= xmin && i < n){
                xmax = max(xmax, s[i][1]);
                i++;
            }
            ans = max(ans, xmax - xmin);
        }
        printf("%d\n", ans);
    }
    return 0;
}
