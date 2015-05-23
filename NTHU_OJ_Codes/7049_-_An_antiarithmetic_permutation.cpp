#include<stdio.h>
#include<list>
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n), n){
		list<int> l;
		for(int i = 0; i < n; i++)
			if(i % 2)
				l.push_back(i);
			else
				l.push_front(i);
		list<int>::iterator it = l.begin();
		printf("%d:", n);
		while(it != l.end()){
			printf(" %d", *it);
			it++;
		}
		putchar(10);
	}
	return 0;
}
