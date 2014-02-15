#include<cstdio>
#include<algorithm>
using namespace std;
int s[100001];
int main(){
	int x, n, m;
	while(scanf("%d%d", &n, &m) > 0){
		for(int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		sort(s, s+n);
		while(m--){
			scanf("%d", &x);
			printf("%d\n", s[x-1]);
		}
	}
	return 0;
}
