#include<stdio.h>
#include<stdlib.h>
int compare(const void *v, const void *o){
        return *(int*)v - *(int*)o;
}
int main(){
    int n ,ct = 0, t, L;
    /*while(scanf("%d", &t) > 0)*/
 scanf("%d", &t);
    while(t--){
        scanf("%d%d",&L, &n);
        int i, s[10011], tot = 0, MAX = 0, MIN = 0;
        for(i = 0; i < n; i++)
            scanf("%d", &s[i]);
        qsort(s, n, sizeof(int), compare);
        int ans = 0;
        for(i = 0; i < n; i++){
            int temp = s[i] > L - s[i]  ?  L - s[i] : s[i];
            if(temp > MIN)
            	MIN = temp;
            if(L - temp > MAX)
            	MAX = L - temp;
        }
        printf("%d %d\n", MIN, MAX);
    }
    return 0;
}
