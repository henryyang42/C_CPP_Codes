#include<stdio.h>
#include<set>
using namespace std;
bool x[1000101];
int main(){
	int n;
	set<int> s;
	for(int i = 2; i < 1000030; i++)
		if(!x[i]){
			s.insert(i);
			for(int j = i+i; j < 1000030; j += i)
				x[j] = true;
		}
	while(scanf("%d", &n) > 0){
		if(s.find(n) != s.end()){
			printf("%d\n", n);
			continue;
		}

		int smaller = *(--s.insert(n).first), bigger = *(++s.insert(n).first);
		if(n - smaller < bigger - n)
			printf("%d\n", smaller);
		else
			printf("%d\n", bigger);
		s.erase(n);
	}
	return 0;
}
