#include<stdio.h>
#include<string.h>
int n, q;
long long tree[400010], lazy[400010];
inline void up(int r){
	tree[r] = tree[r<<1] + tree[r<<1|1];
}
void build(int L, int R, int r){
	lazy[r] = 0;
	if(L == R){
		scanf("%lld", &tree[r]);
		return;
	}
	int mid = (L + R) >> 1;
	build(L, mid, r<<1);
	build(mid+1, R, r<<1|1);
	up(r);
}
inline void down(int L, int R, int mid, int r){
	lazy[r<<1] += lazy[r];
	lazy[r<<1|1] += lazy[r];
	tree[r<<1] += (mid-L+1)*lazy[r];
	tree[r<<1|1] += (R-mid)*lazy[r];
	lazy[r] = 0;
}
long long query(int a, int b, int L, int R, int r){
	if(L >= a && R <= b)
		return tree[r];
	long long ans = 0;
	int mid = (L + R) >> 1;
	if(lazy[r])
		down(L, R, mid, r);
	if(a <= mid)
		ans += query(a, b, L, mid, r<<1);
	if(mid < b)
		ans += query(a, b, mid+1, R, r<<1|1);
	return ans;
}
void update(int a,int b,int c,int L,int R,int r){
	if(a <= L && R <= b){
		lazy[r] += c;
		tree[r] += (long long)(R - L + 1)*c;
	}
	else{
		int mid = (L+R) >> 1;
		if(lazy[r])
			down(L, R, mid, r);
		if(a <= mid)
			update(a, b, c, L, mid, r << 1);
		if(mid < b)
			update(a, b, c, mid+1, R, r<<1|1);
		up(r);
	}
}

int main(){
	while(scanf("%d%d", &n, &q) > 0){
		build(1, n, 1);
		while(q--){
			int a, b, c;
			char op[20];
			scanf("%s", op);
			if(op[0] == 'C'){
				scanf("%d%d%d", &a, &b, &c);
				update(a, b, c, 1, n, 1);
			}
			else{
				scanf("%d%d", &a, &b);
				printf("%lld\n", query(a, b, 1, n, 1));
			}
		}
	}
	return 0;
}
