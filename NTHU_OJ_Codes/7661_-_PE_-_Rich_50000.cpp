#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main(){
	int ct = 0, n, q;
	while(scanf("%d%d", &n, &q) > 0){
		map<string, long long> m;
		for(int i = 0; i < n; i++){
			char s[100];
			long long a, b, c;
			scanf("%s %3lldM%3lldK%3lld", s, &a, &b, &c);
			m[string(s)] = a*1e6+b*1e3+c;
		}
		printf("----Report %d----\n", ++ct);
		while(q--){
			char s[100];
			scanf("%s", s);
			printf("%s %lld\n", s, m[string(s)]);
		}
	}
    return 0;
}