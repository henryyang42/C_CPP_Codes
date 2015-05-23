#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main(){
	int n, k, x;
	while(scanf("%d%d", &n, &k) > 0){
		int pre[10000] = {0};
		for(int i = 1; i <= n; i++)
			scanf("%d", &x), pre[i] = pre[i-1] + x;
		int ans = -1e9;
		for(int i = 0; i <= n; i++)
			for(int j = i; j <= n; j++){
				x = pre[j] - pre[i-1];
				if(x > k && abs(ans-k) > abs(x-k))
					ans = x;
			}
		x = 0;
		if(x > k && abs(ans-k) > abs(x - k))
			ans = x;
		if(ans != -1e9)
			printf("%d\n", ans);
		else
			puts("Cake will lose QAQ");
	}
	return 0;
}
