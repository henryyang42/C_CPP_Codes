#include<stdio.h>
#include<string.h>
int s[1000000];
int sz = 0, temp, now, change;

int top(){
	return s[1];
}
void push(int x){
	s[++sz] = x;
	now = sz;
	while(now > 1 && s[now] > s[now / 2])
		temp = s[now], s[now] = s[now / 2], s[now / 2] = temp, now /= 2;
}
void pop(){
	if(sz == 0) return;
	s[1] = s[sz--];
	now = 1;
	while(now * 2 <= sz){
		change = 2 * now;
		if(!(s[now] < s[change] || change + 1 <= sz && s[now] < s[change + 1]))
			break;
		if(change + 1 <= sz && s[change + 1] > s[change])
			change++;
		temp = s[change], s[change] = s[now], s[now] = temp;
		now = change;
	}
}
int main(){
	char op[10];
	int x;
	while(scanf("%s", op) > 0){
		if(!strcmp(op, "PUSH"))
			scanf("%d", &x), push(x);
		if(!strcmp(op, "POP"))
			pop();
		if(!strcmp(op, "TOP")){
			if(sz)
				printf("%d\n", top());
			else
				puts("Null");
		}
	}
	return 0;
}
