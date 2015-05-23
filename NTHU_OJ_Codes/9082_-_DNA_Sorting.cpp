#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data{
	char DNA[11];
	int unsortness;
}s[1000001];
int compare(const void *v, const void *o){
	struct data *p1 = (struct data*)v, *p2 = (struct data*) o;
	if(p1 -> unsortness != p2 -> unsortness)
		return 	p1 -> unsortness - p2 -> unsortness;
	else
		return strcmp(p1 -> DNA, p2 -> DNA);
}
int main(){
	int n, l, i, j, k;
	while(scanf("%d%d",&l, &n) > 0){
		for(i = 0; i < n; i++)
			scanf("%s", s[i].DNA);
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
