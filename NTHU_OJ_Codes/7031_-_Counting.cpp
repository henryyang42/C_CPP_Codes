#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string add(string a, string b){
	char ans[1000] = {}, fg = 0;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for(int i = 0; i < a.length(); i++)
		ans[i] += a[i] - '0';
	for(int i = 0; i < b.length(); i++)
		ans[i] += b[i] - '0';
	for(int i = 0; i < 1000-1; i++)
		ans[i+1] += ans[i]/10, ans[i] %= 10;
	for(int i = 1000-1; i > 0; i--){
		if(ans[i])
			fg = '0';
		ans[i] += fg;
	}
	ans[0] += '0';
	string Ans = string(ans);
	reverse(Ans.begin(), Ans.end());
	return Ans;
}
string dp[1001] = {"0", "2", "5", "13"};
int main(){
	for(int i = 4; i <= 1000; i++)
		dp[i] = add(add(dp[i-1], dp[i-1]), add(dp[i-2], dp[i-3]));
	int n;
	while(cin >> n)
		cout << dp[n] << "\n";
	return 0;
}
