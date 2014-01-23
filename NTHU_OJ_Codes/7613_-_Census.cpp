#include<stdio.h>
#include<algorithm>
using namespace std;
int tree[2][600][2010], t[600][2010], i, j, n, m, q, lazy[2][600][2010];
inline void up(int s[], int r, int mode){
	if(mode)
		s[r] = max(s[r<<1], s[r<<1|1]);
	else
		s[r] = min(s[r<<1], s[r<<1|1]);
}
void build(int s[], int L, int R, int r, int mode){
	lazy[0][i][r] = lazy[1][i][r] = 0;
    if(R == L){
		s[r] = t[i][L];
    }
	else{
		int mid = (L + R) >> 1;
		build(s, L, mid, r<<1, mode);
		build(s, mid+1, R, r<<1|1, mode);
		up(s, r, mode);
	}
}
int query(int s[], int x, int y, int L, int R, int r, int mode){
	if(L >= x && y >= R)
		return s[r];
	int mid = (L + R) >> 1;
	if(y <= mid)
		return query(s, x, y, L, mid, r<<1, mode);
	else if(x > mid)
		return query(s, x, y, mid+1, R, r<<1|1, mode);
	else{
		if(mode)
			return max(query(s, x, y, L, mid, r<<1, mode), query(s, x, y, mid+1, R, r<<1|1, mode));
		else
			return min(query(s, x, y, L, mid, r<<1, mode), query(s, x, y, mid+1, R, r<<1|1, mode));
	}
}
int find_(int x1, int x2, int y1, int y2, int mode){
	int ans;
	if(mode){
		ans = query(tree[mode][x1], y1, y2, 1, m, 1, mode);
		for(int i = x1 + 1; i <= x2; i++)
			ans = max(ans, query(tree[mode][i], y1, y2, 1, m, 1, mode));
	}
	else{
		ans = query(tree[mode][x1], y1, y2, 1, m, 1, mode);
		for(int i = x1 + 1; i <= x2; i++)
			ans = min(ans, query(tree[mode][i], y1, y2, 1, m, 1, mode));
	}
	return ans;
}
inline void down(int i, int L, int R, int mid, int r, int mode){
	lazy[mode][i][r<<1] += lazy[mode][i][r];
	lazy[mode][i][r<<1|1] += lazy[mode][i][r];
	tree[mode][i][r<<1] += (mid-L+1)*lazy[mode][i][r];
	tree[mode][i][r<<1|1] += (R-mid)*lazy[mode][i][r];
	lazy[mode][i][r] = 0;
}
void update(int i, int x, int y, int c, int L, int R, int r, int mode){
	if(L >= x && R <= y){
		lazy[mode][i][r] += c;
		tree[mode][i][r] += c*(R-L+1);
	}
	else{
		int mid = (L + R) >> 1;
		if(lazy[mode][i][r])
			down(i, L, R, mid, r, mode);
		if(x <= mid)
			update(i, x, y, c, L, mid, r<<1, mode);
		if(mid < y)
			update(i, x, y, c, mid+1, R, r<<1|1, mode);
		up(tree[mode][i], r, mode);
	}
}
int main(){

    char op[2];
    while(scanf("%d%d", &n, &m) > 0){
    	for(i = 1; i <= n; i++){
    		for(j = 1; j <= m; j++)
    			scanf("%d", &t[i][j]);
			build(tree[1][i], 1, m, 1, 1);
			build(tree[0][i], 1, m, 1, 0);
    	}
    	scanf("%d", &q);
    	while(q--){
    		scanf("%s", op);
    		if(op[0] == 'q'){
    			int x1, x2, y1, y2;
    			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    			printf("%d %d\n", find_(x1, x2, y1, y2, 1), find_(x1, x2, y1, y2, 0));
    		}
    		else{
				int x, y, c;
    			scanf("%d%d%d", &x, &y, &c);
    			update(x, y, y, c - t[x][y], 1, m, 1, 0);
    			update(x, y, y, c - t[x][y], 1, m, 1, 1);
    			t[x][y] = c;
    		}
    	}
    }
    return 0;
}
