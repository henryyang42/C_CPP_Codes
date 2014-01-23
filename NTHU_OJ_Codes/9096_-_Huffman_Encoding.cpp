#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

int main(){
	int t, n, x, ct = 1;
	double tot, sig;
	scanf("%d", &t);
	while(t--){
		priority_queue<int, vector<int>, greater<int> > q;
		scanf("%d", &n);
		tot = sig = 0;
		for(int i = 0; i < n; i++)
			scanf("%d", &x), q.push(x), sig += x;
		for(int i = 0; i < n - 1; i++){
			x = q.top();q.pop();
			x += q.top();q.pop();
			q.push(x);
			tot += x;
		}
		printf("Case %d: %.2lf\n", ct++, tot / sig);
	}
	return 0;
}
