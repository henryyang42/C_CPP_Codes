#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n, s[1002];
	while(scanf("%d", &n) > 0){
		for(int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		int gcd = s[0];
		for(int i = 0; i < n; i++)
			gcd = __gcd(gcd, s[i]);
		printf("%d\n", n*gcd);
	}
	return 0;
}