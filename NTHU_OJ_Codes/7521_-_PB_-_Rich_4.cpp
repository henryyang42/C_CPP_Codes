#include<stdio.h>

int main(){
    int n;
    while(scanf("%d", &n) > 0){
     int i;
        long long tot = 0, x;
        for(i = 0; i < n;i++)
            scanf("%lld", &x), tot += x;
        if(tot % n == 0)
            printf("%d\n", n);
        else
            printf("%d\n", n - 1);
    }
	return 0;
}
