#include<stdio.h>
int s[100010];
int sz = 0;
void push(int x){
	int now = ++sz, temp;
	while(now > 1 && x > s[now / 2]){
		s[now] = s[now / 2];
		now /= 2;
	}
	s[now] = x;
}
int top(){
	return s[1];
}
void pop(){
	int parent, child, temp;
	temp = s[sz--];
	parent = 1;
	child = 2;
	while(child <= sz){
		if(child < sz && s[child] < s[child + 1])
			child++;
		if(temp >= s[child])
			break;
		s[parent] = s[child];
		parent = child;
		child *= 2;
	}
	s[parent] = temp;

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
