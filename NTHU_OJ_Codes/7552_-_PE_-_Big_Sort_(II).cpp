#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char s[10000][100];
int compare(const void *v, const void *o){
	char *p1 = (char*)v, *p2 = (char*)o;
	char buffer1[201] = {0}, buffer2[201] = {0};
	strcpy(buffer1, p1);
	strcat(buffer1, p2);
	strcpy(buffer2, p2);
	strcat(buffer2, p1);
	return strcmp(buffer1, buffer2);
}
int main(){
	int n, i;
	while(scanf("%d", &n) > 0, n){
		for(i = 0; i < n; i++)
			scanf("%s", s[i]);
		qsort(s, n, sizeof(char) * 100, compare);
		for(i = 0; i < n; i++)
			printf(s[i]);
		putchar(10);
	}
	return 0;
}
