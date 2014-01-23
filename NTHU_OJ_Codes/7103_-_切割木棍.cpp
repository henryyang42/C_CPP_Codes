#include<stdio.h>
#include<queue>

using namespace std;
int main(){
	int t, n, a, b;
	scanf("%d", &t);
	while(t--){
		priority_queue<int, vector<int>, greater<int> > q;
		scanf("%d%d", &n, &b);
		b = n;
		int ans = 0;
		while(n--)
			scanf("%d", &a), q.push(a);
		n = b-1;
		while(n--){
			a = q.top(), q.pop();
			b = q.top(), q.pop();
			ans += a + b;
			q.push(a + b);
		}
		printf("%d\n", ans);
	}
	return 0;
}
