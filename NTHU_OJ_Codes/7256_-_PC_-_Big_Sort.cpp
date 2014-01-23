#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a, i, l,j,k;
struct bignumber{
	char s[101];
	int l;
}n[100001];
int compare(const void* v, const void*o){
	struct bignumber *p1 = (struct bignumber*)v, *p2 = (struct bignumber*)o;
	int i;
	if(p1 -> s[0] == '-' && p2 -> s[0] =='-'){
		if(p1 -> l != p2 -> l){
			return p2 -> l - p1 -> l;
			}
		else{
			i = 0;
			while(p1 -> s[i] == p2 -> s[i] && i < p1 -> l)
				i++;
			return 	p2 -> s[i] - p1 -> s[i];
		}
	}
	else if(p1 -> s[0] == '-' || p2 -> s[0] =='-'){
		if(p1 -> s[0] =='-')
			return -1;
		else
			return 1;	
	}
	else{
		if(p1 -> l != p2 -> l){
			return p1 -> l - p2 -> l;
		}
		else{
			int i = 0;
			while(p1 -> s[i] == p2 -> s[i] && i < p1 -> l)
				i++;
			return 	p1 -> s[i] - p2 -> s[i];
		}
	}
}

int main(){
	int ct = 0;
	while(scanf("%d",&k)>0)
		{
			if(ct++)
				putchar(10);
			for(i = 0;i < k ;i++)
				scanf("%s",n[i].s),n[i].l = strlen(n[i].s);
			qsort(n,k,sizeof(struct bignumber),compare);
			for(i = 0; i < k ; i++)
				printf("%s\n",n[i].s);
		}
	return 0;
}
