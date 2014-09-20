#include<stdio.h>
#include<list>
using namespace std;

int main(){
	list<int>l;
	char s[3];
	int x;
	while(scanf("%s", s) > 0){
		if(s[0] == 'i'){
			scanf("%d", &x);
			if(s[1] == 'b')
				l.push_front(x);
			else
				l.push_back(x);
		}
		else if(s[0] == 'd' && !l.empty()){
			if(s[1] == 'b')
				l.pop_front();
			else
				l.pop_back();
		}
		else if(s[0] == 'p'){
			if(l.empty())
				puts("null");
			else if(s[1] == 'b')
				printf("%d\n", l.front());
			else
				printf("%d\n", l.back());
		}
	}
	return 0;
}
