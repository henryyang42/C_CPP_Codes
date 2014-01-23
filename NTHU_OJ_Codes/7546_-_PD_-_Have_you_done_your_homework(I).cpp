#include<stdio.h>
#include<list>
using namespace std;
char s[1000001];
int t[1000001];
long long int ans;
void merge_(int l[], int left, int r[], int right, int t[]){
	int ll = 0, rr = 0, tt = 0;
	while(ll < left && rr < right){
		if(l[ll] < r[rr])
			t[tt++] = l[ll++];
		else
			ans += left - ll, t[tt++] = r[rr++];
	}
	while(ll < left)
		t[tt++] = l[ll++];
	while(rr < right)
		t[tt++] = r[rr++];
}
void mergesort(int t[], int n){
	if(n <= 1)
		return;
	const int left = n / 2, right = n - n / 2;
	int l[left], r[right];
	for(int i = 0; i < left; i++)
		l[i] = t[i];
	for(int i = left; i < n; i++)
		r[i - left] = t[i];
	mergesort(l, left);
	mergesort(r, right);
	merge_(l, left, r, right, t);
}

int main(){
	int n;
	while(scanf("%d", &n) > 0){
		scanf("%s",s);
		list<int> num[27];
		for(int i = 0; i < n; i++)
			num[s[i] - 'A'].push_back(i);
		scanf("%s", s);
		for(int i = 0; i < n; i++)
			t[i] = num[s[i] - 'A'].front(), num[s[i] - 'A'].pop_front();
		ans = 0;
		mergesort(t, n);
		printf("%lld\n", ans);
	}
	return 0;
}
