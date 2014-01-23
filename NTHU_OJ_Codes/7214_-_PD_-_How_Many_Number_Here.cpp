#include<stdio.h>
#include<map>
using namespace std;

int main(){
	int n, q, x;
	while(scanf("%d%d", &n, &q) > 0){
		map<int, int> m;
		while(n--)
			scanf("%d", &x), m[x]++;
		while(q--)
			scanf("%d", &x), printf("%d\n", m[x]);
	}
	return 0;
}
