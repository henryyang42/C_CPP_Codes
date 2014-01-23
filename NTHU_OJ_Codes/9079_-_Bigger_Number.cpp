#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int com(const void *v, const void *o){
	char *p1 = (char*)v, *p2 = (char*)o;
	char temp1[21], temp2[21];
	strcpy(temp1, p1), strcpy(temp2, p2);
	strcat(temp1, p2), strcat(temp2, p1);
	return strcmp(temp2, temp1);
}
int main(){
	int n, i; char s[100][10];
	while(scanf("%d", &n) > 0){
		for(i = 0 ; i < n; i++)
			scanf("%s", s[i]);
		qsort(s, n, sizeof(char)*10, com);
		for(i = 0; i < n; i++)
			printf("%s",s[i]);
		putchar(10);
	}
    return 0;
}
