#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[1000][51];
int compare(const void *v, const void *o){
	char *p1 = (char*)v, *p2 = (char*)o;
	return strcmp(p1, p2);
}
int main(){
	int t, tt, i;
	while(scanf("%d", &t) > 0, t){
		tt = t;
		while(tt--)
			scanf("%s", s[tt]);
		qsort(s, t, sizeof(char) * 51, compare);
		for(i = 0; i < t; i++)
			puts(s[i]);
		puts("");
	}
    return 0;
}
