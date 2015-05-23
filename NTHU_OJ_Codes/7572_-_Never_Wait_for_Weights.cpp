#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100001
int leader[MAX], gap[MAX];
int find_(int x){
	gap[x] += gap[leader[x]];
	return x == leader[x] ? x : (leader[x] = find_(leader[x]));
}
int main(){
    char op[10];
    int a, b, w, n, q;
    while(scanf("%d%d", &n, &q) > 0, n + q){
        for(int i = 0; i <= n; i++)
            leader[i] = i, gap[i] = 0;
        while(q--){
            scanf("%s", op);
            if(op[0] == '!'){
                 int a, b, w;
                scanf("%d%d%d", &a, &b, &w);

            }
            else if(op[0] == '?'){
                scanf("%d%d",&a, &b);
				int fa = leader[a], fb = leader[b];
				printf("fa = %d fb = %d\n", fa, fb);
                if(fa == fb)
                    printf("%d\n", gap[b] - gap[a]);
                else
                    puts("UNKNOWN");
            }
        }
    }
    return 0;
}

