#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare(const void *v, const void *o){
	char *p1 = (char*) v, *p2 = (char*)o;
	return strcmp(p1, p2);
}
char s[100001][11];
int main(){
	int n,  ct = 0;
	while(scanf("%d", &n) > 0){
		for(int i = 0; i < n; i++)
			scanf("%s", s[i]);
		qsort(s, n, sizeof(s[0]), compare);
		printf("Case %d\n", ++ct);
		for(int i = 0; i < n; i++){
			int temp = i, tot = 0;
			while(!strcmp(s[i], s[temp]))
				i++, tot++;
			printf("%s %d\n", s[temp], tot);
			i--;
		}
	}
	return 0;
}
