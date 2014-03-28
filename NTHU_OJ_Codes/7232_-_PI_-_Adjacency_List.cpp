#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
	int n, m, a, b;
	while(scanf("%d%d", &n, &m) > 0){
		string op;
		map<pair<int, int>, int>M;
		while(m--){
			cin >> op >> a >> b;
			if(op == "Connect"){
				M[make_pair(a, b)] = 1;
			}
			else if(op == "Ask"){
				puts(M[make_pair(a, b)] ? "Yes" : "No");
			}
			else{
				if(!M[make_pair(a, b)])
					puts("Error");
				M[make_pair(a, b)] = 0;	
			}
		}
	}
	return 0;
}