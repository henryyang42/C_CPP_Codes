#include<stdio.h>
int s[100010];
int sz = 0;
void push(int x){
	s[++sz] = x;
	int now = sz, temp;
	while(now > 1 && s[now] > s[now / 2])
		temp = s[now], s[now] = s[now / 2], s[now / 2] = temp, now /= 2;
}
int top(){
	return s[1];
}
void pop(){
	s[1] = s[sz--];
	int now = 1;
	while(now * 2 <= sz){
		int change = 2 * now, temp;
		if(!(s[change] > s[now] || change + 1 <= sz && s[change + 1] > s[now]))
			break;
		if(change + 1 <= sz && s[change + 1] > s[change])
			change++;
		temp = s[change], s[change] = s[now], s[now] = temp;
		now = change;
	}
}
int main(){
	int x, i, q, N;
	char op[10];
	while(scanf("%d%d", &N, &q) >0){
		sz = 0;
		while(q--){
			scanf("%s%d",op, &x);
			switch(op[0]){
				case 'U':
					for(i = 0; i < x; i++){
						if(i)
							putchar(32);
						printf("%d", top());
						pop();
					}
					putchar(10);
					break;
				case 'P':
					if(sz < N )
						push(x);
					else if(sz >= N  && x < top())
						push(x), pop();
			}
		}
	}
	return 0;
}
