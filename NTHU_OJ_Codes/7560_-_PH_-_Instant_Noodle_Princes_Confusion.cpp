#include<stdio.h>
#include<stdlib.h>

struct data{
	int in, exp;
}s[100001];
int compare1(const void *v, const void *o){
	data *p1 = (data*) v, *p2 = (data*)o;
	if(p1 -> in - p2 -> in)
		return p1 -> in - p2 -> in;
	return p1 -> exp- p2 -> exp;
}
struct data heap[100001];
int sz = 0;
void pop(){
	heap[1] = heap[sz--];
	int now = 1, change;
	struct data temp;
	while(now * 2 <= sz){
		change = 2 * now;
		if(!(heap[now].exp > heap[change].exp || change + 1 <= sz && heap[now].exp > heap[change + 1].exp))
			break;
		if(change + 1 <= sz && heap[change].exp > heap[change + 1].exp)
			change++;
		temp = heap[change], heap[change] = heap[now], heap[now] = temp;
		now = change;
	}
}
void push(struct data x){
	heap[++sz] = x;
	int now = sz;
	struct data temp;
	while(now > 1 && heap[now].exp < heap[now / 2].exp)
		temp = heap[now], heap[now] = heap[now / 2], heap[now / 2] = temp, now /= 2;
}
struct data top(){
	return heap[sz];
}
int main(){
	int n, a, b, ct = 0, fg, i, now = 0;
	while(scanf("%d", &n) > 0){
		for(int i = 0; i < n; i++)
			scanf("%d%d", &s[i].in, &s[i].exp), s[i].exp += s[i].in-1;
		qsort(s, n, sizeof(data), compare1);
		fg = 1, now = 0;
		for(i = 1, sz = 0; i <= n; i++){
			struct data temp;
			while(s[now].in == i && now < n)
				push(s[now++]);
			while(sz && top().exp < i)
				pop();
			if(sz)
				pop();
			else
				fg = 0;
		}
		printf("Case %d: ", ++ct);
		if(fg)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
