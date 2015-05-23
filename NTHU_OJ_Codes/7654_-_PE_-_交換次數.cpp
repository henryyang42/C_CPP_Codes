#include<cstdio>
int s[1000001];
long long ct;
void merge(int s[], int ll[], int rr[], int left, int right){
	int ind = 0, r = 0, l = 0;
	while(r < right && l < left){
		if(ll[l] > rr[r]){
			ct += left - l;
			s[ind++] = rr[r++];
		}
		else
			s[ind++] = ll[l++];
	}
	while(r < right)
		s[ind++] = rr[r++];
	while(l < left)
		s[ind++] = ll[l++];
}
void merge_sort(int s[], int l){
	if(l == 1)
		return;
	int left = l/2, right = l - l/2;
	int ll[left], rr[right];
	for(int i = 0; i < left; i++)
		ll[i] = s[i];
	for(int i = 0; i < right; i++)
		rr[i] = s[i+left];
	merge_sort(ll, left);
	merge_sort(rr, right);
	merge(s, ll, rr, left, right);
}
int main(){
	int n;
	while(scanf("%d", &n) > 0){
		ct = 0;
		for(int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		merge_sort(s, n);
		printf("%lld\n", ct);
	}
	return 0;
}
