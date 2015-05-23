#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string s, t;
	while(cin >> s >> t){
		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());
		int ans[10000] = {};
		for(int i = 0; i < s.length(); i++)
			for(int j = 0; j < t.length(); j++)
				ans[i+j] += (s[i]-48) * (t[j]-48);
		for(int i = 0; i < 10000 - 1; i++)
			ans[i+1] += ans[i] / 10, ans[i] %= 10;
		int x = 9999;
		while(x >= 0 && ans[x] == 0)
			x--;
		if(x == -1)
			puts("0");
		else{
			while(x >= 0)
				putchar(ans[x--] + '0');
			putchar(10);
		}
	}
	return 0;
}
