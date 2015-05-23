#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	int n, x, isget;
	while(scanf("%d", &n), n){
		map<int, int> m[2];
		isget = 0;
		while(n--)
			scanf("%d", &x), m[0][x]++;
		scanf("%d", &n);
		while(n--)
			scanf("%d", &x), m[1][x]++;
		for(map<int, int>::iterator it = m[0].begin(); it != m[0].end(); it++)
			if(it -> second && m[1][it -> first]){
				int ct = min(it -> second, m[1][it -> first]);
				while(ct--){
					if(isget++)
						putchar(32);
					printf("%d", it -> first);
				}
			}
		if(!isget)
			printf("empty");
		putchar(10);
	}
	return 0;
}
