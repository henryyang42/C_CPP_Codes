#include<stdio.h>
#include<string.h>
struct data{
	int x, pos;
}s[100001];
int t[100001];
long long ct[100001];
long long int ans;
void merge_(data l[], int left, data r[], int right, data t[]){
	int ll = 0, rr = 0, tt = 0;
	while(ll < left && rr < right){
		if(l[ll].x > r[rr].x)
			t[tt++] = r[rr], ct[r[rr++].pos] += left - ll;
		else if(l[ll].x <= r[rr].x)
			t[tt++] = l[ll++];

	}
	while(ll < left)
		t[tt++] = l[ll++];
	while(rr < right)
		t[tt++] = r[rr++];
}
void mergesort(data t[], int n){
	if(n <= 1)
		return;
	const int left = n / 2, right = n - n / 2;
	data l[left], r[right];
	for(int i = 0; i < left; i++)
		l[i] = t[i];
	for(int i = left; i < n; i++)
		r[i - left] = t[i];
	mergesort(l, left);
	mergesort(r, right);
	merge_(l, left, r, right, t);
}

int main(){
	int n, q, a, b;
	while(scanf("%d %d", &n, &q) > 0){
		memset(ct, 0, sizeof(ct));
		for(int i = 0; i < n; i++)
			scanf("%d", &s[i].x), s[i].pos = i;
		mergesort(s, n);
		for(int i = 0; i < q; i++){
			scanf("%d%d", &a, &b), printf("%lld %lld ", ct[a - 1], ct[b - 1]);
			if(ct[a - 1] > ct[b - 1])putchar('R');
			if(ct[a - 1] < ct[b - 1])putchar('C');
			if(ct[a - 1] == ct[b - 1])putchar('S');
			putchar(10);
		}
		putchar(10);
	}
	return 0;
}
