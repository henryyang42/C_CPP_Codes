#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data{
	int x, ct, pos;
}s[1000001];
int ct[1000001];
typedef struct data D;
int cmp(const void *v, const void *o){
	D *p1 = (D*)v, *p2 = (D*) o;
	if(p1 -> x != p2 -> x)
		return p1 -> x - p2 -> x;
	return p1 -> ct - p2 -> ct;
}
int main(){
	int n, q, i, x, t;
	while(scanf("%d%d", &n, &q) > 0){
		for(i = 0; i < n + 1; i++)
			ct[i] = 0;
		for(i = 0; i < n; i++){
			scanf("%d", &x);
			ct[x]++;
			s[i].x = x, s[i].ct = ct[x], s[i].pos = i + 1;
		}
		qsort(s, n, sizeof(D), cmp);
		for(i = 0; i < q; i++){
			scanf("%d%d", &t, &x);
			D test, *found;
			test.x = x, test.ct = t;
			found = (D*)bsearch(&test, s, n, sizeof(D), cmp);
			if(found)
				printf("%d\n", found -> pos);
			else
				puts("0");
		}
	}
	return 0;
}
