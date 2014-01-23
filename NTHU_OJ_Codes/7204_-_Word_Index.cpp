#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int ansct;
struct data{
	char s[6];
	int no;
}ans[90000], ss;
char curr[6], ct[6] = {0};
void dfs(int n, int I, int end){
	int i;
	if(n == end){
		curr[end] = 0;
		ans[ansct].no = ansct;
		strcpy(ans[ansct++].s,curr);
		return;
	}
	for(i = I; i < 26; i++)
		if(!ct[i]){
			ct[i] = 1;
			curr[n] = i + 'a';
			dfs(n + 1, i + 1, end);
			ct[i] = 0;	
		}
}
int compare(const void *v, const void *o){
	struct data *p1 = (struct data*)v, *p2 = (struct data*)o;
	return strcmp(p1  -> s, p2 -> s);	
}
int main(){
	int i, tot;
	char s[6];
	ansct = 0;
	for(i = 1; i < 6; i++)
		memset(ct, 0, sizeof(ct)), dfs(0, 0, i);
	qsort(ans, ansct, sizeof(struct data), compare);
	while(scanf("%s", ss.s) > 0){
		struct data *found = (struct data*)bsearch( &ss, ans, ansct, sizeof(struct data), compare);
		if(found != NULL)
			printf("%d\n", (found -> no) + 1);
		else
			puts("0");	
	}
	return 0;
}
