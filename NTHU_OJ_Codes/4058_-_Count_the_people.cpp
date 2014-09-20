#include<stdio.h>
#include<stdlib.h>
struct data{
	double num;
	int tag;	
}s[1000020];
int compare(const void *v, const void *o){
	struct data *p1 = (struct data*)v, *p2 = (struct data*)o;
	if(p1 -> num > p2 -> num)
		return 1;
	else if(p1 -> num < p2 -> num)
		return -1;
	else
		return 0;
}
int ans[1001] = {0};
int main(){
	int i, j, ct = 0;
	for(i = 0; i <= 1000; i++)
		for(j = 0; j < i; j++)
			if(j){
				double ii = i, jj = j;
				s[ct].tag = 0;
				s[ct++].num = ii / jj;	
			}
	qsort(s, ct, sizeof(struct data), compare);
	for(i = 1; i <= 1000; i++){
		ans[i] = ans[i - 1];
		for(j = 0; j < i; j++){
			double ii = i, jj = j, target;
			target = jj / ii;
			struct data *found = (struct data*) bsearch(&target, s,  ct, sizeof(struct data), compare);
		}
				
	}
	return 0;
}
