#include<stdio.h>
#include<map>
using namespace std;
int main(){
	int n, m, i, x;
	while(scanf("%d", &n) > 0, n){
		map<int, int> map1, map2;
		for(i = 0; i < n; i++)
			scanf("%d", &x), map1[x] = 1;
		scanf("%d", &m);
		for(i = 0; i < m; i++)
			scanf("%d", &x), map2[x] = 1;
		int fg = 0;
		map<int, int>::iterator it = map1.begin();
		while(it != map1.end()){
			if(map2[it -> first] == 1)
				printf("%s%d", fg++ ? " " : "", it -> first);
			it++;
		}
		if(fg == 0)
			puts("empty");
		else
			putchar(10);
	}
	return 0;
}
