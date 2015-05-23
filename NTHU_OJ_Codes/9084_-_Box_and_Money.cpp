#include<stdio.h>
#include<stdlib.h>
struct Box{
    int tot, i, s[1001], sz;
}box[10001];
int compare(const void *v, const void *o){
    return *(int*)v - *(int*)o;
}
int comparebox(const void *v, const void *o){
    Box *p1 = (Box*)v, *p2 = (Box*)o;
    if(p1 -> tot != p2 -> tot)
        return p2 -> tot - p1 -> tot;
    return p1 -> i - p2 -> i;
}
int main(){
    int n, ct = 0;
    while(scanf("%d", &n), n){
        if(ct++)
            putchar(10);
        for(int i = 0; i < n; i++){
            int x;
            box[i].tot = box[i].sz = 0, box[i].i = i;
            while(scanf("%d", &x), x){
                box[i].s[box[i].sz++] = x;
                box[i].tot += x;
            }
        }
        qsort(box, n, sizeof(box[1]), comparebox);
        for(int i = 0; i < n; i++){
            qsort(box[i].s, box[i].sz, sizeof(int), compare);
            for(int j = 0; j < box[i].sz; j++){
                if(j)
                    putchar(32);
                printf("%d", box[i].s[j]);
            }
            putchar(10);
        }
    }
    return 0;
}
