#include<stdio.h>
#include<algorithm>
using namespace std;
unsigned long long ans[41] = {0, 1, 5, 11};
int main(){
	int t, n;
	for(int i = 4; i <= 40; i++)
		ans[i] = ans[i-1] + 4*ans[i-2] + 2*ans[i-3];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%llu\n", ans[n]);
	}
	return 0;
}
