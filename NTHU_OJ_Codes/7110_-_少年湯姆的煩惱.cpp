#include<stdio.h>
#include<algorithm>
using namespace std;
int s[1000001];
int main(){
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		sort(s, s+n);
		printf("%d\n", s[n%2? n/2:n/2-1]);
	}
	return 0;
}
