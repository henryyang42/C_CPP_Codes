#include<stdio.h>
#include<algorithm>
using namespace std;
int s[100001];
int calc(){
	int temp = 0, n, k, ans = 1e9;
	scanf("%d%d", &n, &k);
	int from = 0, to = 0;
	for(to = 0; to < n; to++){
		scanf("%d", &s[to]);
		temp += s[to];
		while(temp >= k && to >= from){
			ans = min(ans, to - from + 1);
			temp -= s[from];
			from++;
		}
	}
	return ans == 1e9 ? 0 : ans;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--)
		printf("%d\n", calc());
	return 0;
}
