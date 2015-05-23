#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
	int num, l;
	char pos[300];
}node[300];
int isvalid = 1;
int pos(char s[1000]){
	int now = 1, i;
	for(i = 0; i < s[i]; i++)
		if(s[i] == 'L')
			now = now * 2;
		else if(s[i] == 'R')
			now = now * 2 + 1;
	return now;
}
int compare(const void*v, const void *o){
	struct data *p1 = (struct data*)v, *p2 = (struct data*)o;
	if(p1 -> l - p2 -> l)
		return p1 -> l - p2 -> l;
	int cmp = strcmp(p1 -> pos, p2 -> pos);
	if(!cmp) isvalid = 0;
	return cmp;
}
int findparent(int k){
	int i;
	if(node[k].l == 0)
		return 1;
	for(int i = k - 1; i >= 0; i--)
		if(node[k].l - 1 == node[i].l && (node[k].l == 1 || strstr(node[k].pos, node[i].pos) == node[k].pos)){
			return 1;
		}
	return 0;
}
int main(){
	char s[1000], path[1000];
	int ct = 0, i;
	while(scanf("%s", s) > 0){
		if(s[0] == '(' && s[1] == ')'){
			qsort(node, ct, sizeof(struct data), compare);
			/*for(i = 0; i < ct; i++)
				printf("%s %d %d\n", node[i].pos, node[i].l, node[i].num);*/
			if(isvalid)
				for(i = 0; i < ct; i++)
					isvalid &= findparent(i);
			if(isvalid){
				for(i = 0; i < ct; i++){
					if(i)
						putchar(32);
					printf("%d", node[i].num);
				}
				putchar(10);
			}
			else
				puts("not complete");
			ct = 0;
			isvalid = 1;
			continue;
		}
		int num;
		sscanf(s, "(%d,%s)", &num, path);
		int l = strlen(path) - 1;
		path[l] = 0;
		node[ct].num = num, strcpy(node[ct].pos, path), node[ct++].l = l;
	}
	return 0;
}
