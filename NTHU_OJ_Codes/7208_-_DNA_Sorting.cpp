#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data{
	int id;
	char DNA[101];
	int unsortness;
}s[101];
int compare(const void *v, const void *o){
	struct data *p1 = (struct data*)v, *p2 = (struct data*) o;
	if(p1 -> unsortness != p2 -> unsortness)
		return 	p1 -> unsortness - p2 -> unsortness;
	else
		return p1 -> id - p2 -> id;
}
int main(){
	int n, l, i, j, k, t, ct = 0;
	while(scanf("%d", &t) > 0)while(t--){
		if(ct++)
			putchar(10);
		scanf("%d%d",&l, &n);
		for(i = 0; i < n; i++)
			scanf("%s", s[i].DNA), s[i].id = i;
		for(i = 0; i < n; i++){
			s[i].unsortness = 0;
			for(j = 0; j < l; j++)
				for(k = j + 1; k < l; k++)
					if(s[i].DNA[j] > s[i].DNA[k])
						s[i].unsortness++;
		}
		qsort(s, n, sizeof(struct data), compare);
		for(i = 0; i < n; i++)
			puts(s[i].DNA);
	}
    return 0;
}
