#include<stdio.h>
#include<set>
#include<map>
using namespace std;
int s[1000001];
int calc(int n){
	set<int> S;
	map<int, int> M;
	for(int i = 0; i < n; i++)
		scanf("%d", &s[i]), S.insert(s[i]);
	int from = 0, to = 0, ans = 1e9;
	for(to = 0; to < n; to++){
		M[s[to]]++;
		if(M.size() == S.size()){
			while(M.size() == S.size()){
				ans = ans < (to - from + 1) ? ans : (to - from + 1);
				M[s[from]]--;
				if(M[s[from]] == 0)
					M.erase(s[from]);
				from++;
			}
		}
	}
	return ans;
}
int main(){
	int n;
	while(scanf("%d", &n) > 0)
		printf("%d\n", calc(n));
	return 0;
}


