#include<stdio.h>
int s[100010];
int sz = 0;
void push(int x){
	int now = ++sz, temp;
	while(now > 1 && x < s[now / 2]){
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
		if(child < sz && s[child] > s[child + 1])
			child++;
		if(temp <= s[child])
			break;
		s[parent] = s[child];
		parent = child;
		child *= 2;
	}
	s[parent] = temp;

}
int main(){
	int n, x, i;
	while(scanf("%d", &n) > 0, n){
		sz = 0;
		for(i = 0; i < n; i++)
			scanf("%d", &x), push(x);
		long long  tot = 0, temp;
		while(sz > 1){
			temp = top();
			pop();
			temp += top();
			pop();
			tot += temp;
			push(temp);
		}
		printf("%lld\n", tot);
	}
	return 0;
}
