#include<stdio.h>
#include<algorithm>
using namespace std;
int n, q, tree_max[200010], tree_min[200010];
inline void up(int r){
	tree_max[r] = max(tree_max[r<<1], tree_max[r<<1|1]);
	tree_min[r] = min(tree_min[r<<1], tree_min[r<<1|1]);
}
void build(int L, int R, int r){
	if(L == R){
		scanf("%d", &tree_max[r]);
		tree_min[r] = tree_max[r];
		return;
	}
	int mid = (L + R) >> 1;
	build(L, mid, r<<1);
	build(mid+1, R, r<<1|1);
	up(r);
}
int find_max(int a, int b, int L, int R, int r){
	if(a <= L && b >= R)
		return tree_max[r];
	int mid = (L + R) >> 1;
	if(b <= mid)
		return find_max(a, b, L, mid, r<<1);
	else if(mid < a)
		return find_max(a, b, mid+1, R, r<<1|1);
	else
		return max(find_max(a, b, L, mid, r<<1), find_max(a, b, mid+1, R, r<<1|1));
}
int find_min(int a, int b, int L, int R, int r){
	if(a <= L && b >= R)
		return tree_min[r];
	int mid = (L + R) >> 1;
	if(b <= mid)
		return find_min(a, b, L, mid, r<<1);
	else if(mid < a)
		return find_min(a, b, mid+1, R, r<<1|1);
	else
		return min(find_min(a, b, L, mid, r<<1), find_min(a, b, mid+1, R, r<<1|1));
}
int main(){
	while(scanf("%d%d", &n, &q) > 0){
		build(1, n, 1);
		while(q--){
			int a, b;
			scanf("%d%d", &a, &b);
			printf("%d\n", find_max(a, b, 1, n, 1) - find_min(a, b, 1, n, 1));
		}
	}
	return 0;
}
