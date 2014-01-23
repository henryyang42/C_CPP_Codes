#include<stdio.h>
#include<string.h>
char s[100], t[100];
void recovery(int sstart, int send, int tstart, int tend){
    int mid;
    if(sstart == send) return;
    for(mid = tstart; mid < tend; mid++)
        if(s[sstart] == t[mid])
            break;printf("%d ", mid);
    recovery(sstart+1, sstart+1+mid-tstart, tstart, mid);
    recovery(sstart+1+mid-tstart+1, send, mid+1, tend);
    putchar(s[sstart]);
}
int main(){
    while(scanf("%s%s", s, t) > 0){
        recovery(0, strlen(s), 0, strlen(s));
        putchar(10);
    }
    return 0;
}
