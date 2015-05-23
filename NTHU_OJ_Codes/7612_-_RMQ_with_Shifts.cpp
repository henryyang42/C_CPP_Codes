#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
using namespace std;
int n, q, tree[400010], s[100010], lazy[400010];
inline void up(int r){
	tree[r] = min(tree[r<<1], tree[r<<1|1]);
}
inline void down(int L, int R, int mid, int r){
	lazy[r<<1] += lazy[r];
	lazy[r<<1|1] += lazy[r];
	tree[r<<1] += lazy[r]*(mid-L+1);
	tree[r<<1|1] += lazy[r]*(R-mid);
	lazy[r] = 0;
}
void build(int L, int R, int r){
	lazy[r] = 0;
	if(L == R){
		scanf("%d", &s[L]);
		tree[r] = s[L];
	}
	else{
		int mid = (L + R) >> 1;
		build(L, mid, r<<1);
		build(mid+1, R, r<<1|1);
		up(r);
	}
}
void update(int x, int y, int z, int L, int R, int r){
	if(x <= L && y >= R){
		lazy[r] += z;
		tree[r] += z*(R-L+1);
	}
	else{
		int mid = (L + R) >> 1;
		if(lazy[r])
			down(L, R, mid, r);
		if(mid >= x)
			update(x, y, z, L, mid, r<<1);
		if(mid < y)
			update(x, y, z, mid+1, R, r<<1|1);
		up(r);
	}
}

int query(int x, int y, int L, int R, int r){
	if(x <= L && y >= R)
		return tree[r];
	else{
		int mid = (L + R) >> 1;
		if(mid >= y)
			return query(x, y, L, mid, r<<1);
		else if(mid < x)
			return query(x, y, mid+1, R, r<<1|1);
		else
			return min(query(x, y, L, mid, r<<1), query(x, y, mid+1, R, r<<1|1));
	}
}

int gettok(char s[], int get[]){
	int ct = 0;
	char *ptr = strtok(s, ",)");
	get[ct++] = atoi(ptr);
	while((ptr = strtok(NULL, ",)")) != NULL)
		get[ct++] = atoi(ptr);
	return ct;
}
int main(){
	scanf("%d%d", &n, &q);
	build(1, n, 1);
	char str[100];
	int ct, get[100], to[100];
	while(q--){
		scanf("%s", str);
		str[5] = 0;
		if(strcmp(str, "query") == 0){
			ct = gettok(str+6, get);
			int a = get[0], b = get[1];
			printf("%d\n", query(a, b, 1, n, 1));
		}
		else{
			ct = gettok(str+6, get);
			for(int i = 0; i < ct; i++)
				to[i] = s[get[(i+1)%ct]];
			for(int i = 0; i < ct; i++){
				update(get[i], get[i], to[i] - s[get[i]], 1, n, 1);
				s[get[i]] = to[i];
			}
		}
	}
	return 0;
}

