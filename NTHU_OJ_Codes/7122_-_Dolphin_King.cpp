#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
map<int, int> ct;
int s[50001];
int t[50001];
void merge_(int l[], int left, int r[], int right, int s[]){
	int i = 0, rr = 0, ll = 0;
	while(ll < left && rr < right){
		if(l[ll] > r[rr])
			s[i++] = l[ll++];
		else{
			s[i++] = r[rr];
			if(ct.find(r[rr]) == ct.end())
				ct[r[rr++]] = left - ll;
			else
				ct[r[rr++]] += left - ll;
		}
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
		ct.clear();
		for(i = 0; i < n; i++)
			scanf("%d", &s[i]), t[i] = s[i];
		mergesort(s, n);
		scanf("%d", &q);
		printf("Case %d:\n", ++casect);
		for(i = 0; i < q; i++)
			scanf("%d", &x), printf("%d\n", ct[t[x]]);
		putchar(10);
	}
	return 0;
}
