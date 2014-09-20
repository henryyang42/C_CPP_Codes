#include<stdio.h>
#include<stdlib.h>
typedef struct list{
	int num;
	struct list * next;
}L;
L *root, *temp, *now, *curr, *prev;
L* generate(int num){
	L *temp = (L*) malloc(sizeof(L));
	temp -> num = num;
	temp -> next = 0;
	return temp;
}
void construct(int n){
	now = root = generate(1);
	curr = root;
	int i;
	for(i = 2; i <= n; i++){
		temp = generate(i);
		curr -> next = temp;
		curr = temp;
	}
	curr -> next = root;
	prev = curr;
}
void travel(int ct){
	while(ct--)
		prev = now, now = now -> next;
	temp = now;
	now = now -> next;
	prev -> next = now;
	free(temp);	
}
int main(){
	int N, M;
	while(scanf("%d%d", &N, &M) > 0, M + N){
		construct(N);
		while(--N)
			travel((M - 1) % (N + 1));
		printf("%d\n",now -> num);
		free(now);
	}
	return 0;
}
