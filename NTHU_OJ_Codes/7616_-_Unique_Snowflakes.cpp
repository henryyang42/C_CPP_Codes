#include<stdio.h>
#include<set>
using namespace std;
int s[1000001];
int calc(){
	int n, ans = 0;
	set<int> S;
	scanf("%d", &n);
	int from = 0, to = 0;
	for(to = 0; to < n; to++){
		scanf("%d", &s[to]);
		if(S.find(s[to]) == S.end()){
			S.insert(s[to]);
			ans = ans > S.size() ? ans : S.size();
		}
		else{
			while(s[from] != s[to])
				S.erase(s[from++]);
			while(s[from] == s[to] && from < to)
				from++;
			S.insert(s[to]);
		}
	}
	return ans;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--)
		printf("%d\n", calc());
	return 0;
}

