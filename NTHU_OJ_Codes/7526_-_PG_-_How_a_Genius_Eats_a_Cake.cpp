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
int travel(int ct){
	int i;
	while(ct-- > 0)
		prev = now, now = now -> next;
	temp = now;
	now = now -> next;
	prev -> next = now;
	i = temp -> num;
	free(temp);
	return i;
}
int main(){
	int N, M, i;
	long long fib[100];
    fib[0] = 0, fib[1] = 1;
    for(i = 2; i < 62; i++){
        fib[i ] = fib[i-1] + fib[i-2];
    }
	while(scanf("%d", &N) > 0, N){
		construct(N);
		i = 1;
		while(--N)
			travel((fib[i++] - 1) % (N + 1));
		printf("%d\n",now -> num);
		free(now);
	}
	return 0;
}
