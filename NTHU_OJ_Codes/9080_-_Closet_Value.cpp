#include<stdio.h>
#include<map>
int Abs(int x){
	return x > 0 ? x : -x;
}
using namespace std;
int main(){
	int n, x;
	while(scanf("%d", &n) > 0){
		map<int, int> m;
		scanf("%d", &x);
		m[x] = 1;
		printf("0");
		for(int i = 1; i < n; i++){
			scanf("%d", &x);
			if(m[x]){
				printf(" 0");
			}
			else{
				map<int, int>::iterator it = m.insert(pair<int, int>(x, 1)).first, temp;
				int min = 2147483647;
				temp = it;
				m[x] = 1;
				if(temp != m.begin())
					min = Abs(x -(--temp) -> first);
				temp = it;
				if(++temp != m.end())
					if(min > Abs(x - (temp) -> first))
							min = Abs(x - (temp) -> first);
				printf(" %ld", min);
			}
		}
		putchar(10);
	}
	return 0;
}
