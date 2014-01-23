#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int n, k, s[100], i;
    while(scanf("%d%d", &n, &k) > 0, n + k){
        for(i = 0; i < n; i++)
            scanf("%d", &s[i]);
        sort(s, s + n);
        while(k--)
            prev_permutation(s, s + n);
        for(i = 0; i < n; i++){
            if(i)
                putchar(32);
             printf("%d", s[i]);


        }
        putchar(10);
    }
    return 0;
}
