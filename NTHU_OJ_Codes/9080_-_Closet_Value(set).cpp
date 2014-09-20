#include<stdio.h>
#include<set>
int Abs(int x){
	return x > 0 ? x : -x;
}
using namespace std;
int main(){
	int n, x;
	while(scanf("%d", &n) > 0){
		set<int> s;
		scanf("%d", &x);
		s.insert(x);
		printf("0");
		for(int i = 1; i < n; i++){
			scanf("%d", &x);
			if(s.find(x) != s.end()){
				printf(" 0");
			}
			else{
				set<int>::iterator it = s.insert(x).first, temp;
				int min = 2147483647;
				temp = it;
				if(temp != s.begin())
					min = Abs(x - *(--temp));
				temp = it;
				if(++temp != s.end())
					if(min > Abs(x - *(temp)))
							min = Abs(x - *(temp));
				printf(" %ld", min);
			}
		}
		putchar(10);
	}
	return 0;
}
