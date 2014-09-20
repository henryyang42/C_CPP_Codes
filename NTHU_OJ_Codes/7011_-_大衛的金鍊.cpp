#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(int a, int b){
	return a > b;
}
int main(){
	int t, n, x;
	scanf("%d", &t);
	while(t--){
		vector<int> v;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &x), v.push_back(x);
		make_heap(v.begin(), v.end(), compare);
		long long ans = 0;
		for(int i = 0; i < n - 1; i++){
			int temp = v.front();
			pop_heap(v.begin(), v.end(), compare), v.pop_back();
			temp += v.front();
			pop_heap(v.begin(), v.end(), compare), v.pop_back();
			ans += temp;
			v.push_back(temp), push_heap(v.begin(), v.end(), compare);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
