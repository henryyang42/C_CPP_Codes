#include<stdio.h>
int s[1000001];
long long tot;
void merge_(int l[], int left, int r[], int right, int s[]){
	int i = 0, rr = 0, ll = 0;
	while(ll < left && rr < right){
		if(l[ll] > r[rr])
			s[i++] = l[ll++], tot += right - rr;
		else
			s[i++] = r[rr++];
	}
	while(left > ll)
		s[i++] = l[ll++];
	while(right > rr)
		s[i++] = r[rr++];
}
void mergesort(int s[], int n){
	if(n <= 1)
		return;
	const int left = n / 2, right = n - n / 2;
	int l[left], r[right], i;
	for(i = 0; i < left; i++)
		l[i] = s[i];
	for(i = left; i < n; i++)
		r[i - left] = s[i];
	mergesort(l, left);
	mergesort(r, right);
	merge_(l, left, r, right, s);
}
int main(){
	int n, q, i, x, casect= 0;
	while(scanf("%d", &n) > 0){
		for(i = 0; i < n; i++)
			scanf("%d", &s[i]);
		tot = 0;
		mergesort(s, n);
		printf("Minimum exchange operations : %lld\n", tot);
	}
	return 0;
}
