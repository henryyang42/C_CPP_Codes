#include<algorithm>
#include<stdio.h>
int abs(int x){
	return x < 0 ? -x : x;
}
using namespace std;
int s[100000];
int main(){
	int t, n, tot;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", s+i);
		sort(s, s + n);
		tot = 0;
		for(int i = 0; i < n; i++)
			tot += abs(s[i] - s[n/2]);
		printf("%d\n", tot);
	}
	return 0;
}
