#include<stdio.h>

int main(){
    int n ,ct = 0, t, L, x;
 	scanf("%d", &t);
    while(t--){
        scanf("%d%d",&L, &n);
        int i, tot = 0, MAX = 0, MIN = 0;
        for(i = 0; i < n; i++){
            scanf("%d", &x);
            int temp = x > L - x  ?  L - x : x;
            if(temp > MIN)
            	MIN = temp;
            if(L - temp > MAX)
            	MAX = L - temp;
        }
        printf("%d %d\n", MIN, MAX);
    }
    return 0;
}
