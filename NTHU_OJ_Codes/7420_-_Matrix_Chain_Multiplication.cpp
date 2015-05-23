#include <map>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

int main(){
	int t, a, b, c, ans;
	string s;
	map<char, pair<int, int> >m;
	cin >> t;
	while(t--){
		cin >> s >> a >> b;
		m[s[0]] = make_pair(a, b);
	}
	while(cin >> s){
		ans = 0;
		pair<int, int>ma, mb;
		stack<pair<int, int> >stk;
		for(int i = 0; i < s.length() && ans >= 0; i++){
			if(s[i] == ')'){
				mb = stk.top(); stk.pop();
				ma = stk.top(); stk.pop();
				if(ma.second != mb.first)
					ans = -1;
				else{
					ans += ma.first*ma.second*mb.second;
					stk.push(make_pair(ma.first, mb.second));
				}
			}
			else if(s[i] == '('){}
			else
				stk.push(m[s[i]]);
		}
		if(ans == -1)
			cout << "error\n";
		else
			cout << ans << "\n";
	}
	return 0;
}
