#include<iostream>
#include<string>
#include<algorithm>
#define MAX 1000
using namespace std;
string add(string a, string b){
	int temp[MAX] = {}, x = MAX-1;
	char str[MAX] = {};
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for(int i = 0; i < a.length(); i++)
		temp[i] += a[i] - '0';
	for(int i = 0; i < b.length(); i++)
		temp[i] += b[i] - '0';
	for(int i = 0; i < MAX-1; i++)
		temp[i+1] += temp[i]/10, temp[i] %= 10;
	while(x >= 0 && temp[x] == 0)
		x--;
	for(int i = 0; i <= x; i++)
		str[i] = temp[i] + '0';
	string ans(str);
	reverse(ans.begin(), ans.end());
	return ans;
}
int compare(string &a, string &b){
	if(a == b)
		return 0;
	if(a.length() > b.length() || a.length() == b.length() && a > b)
		return 1;
	return -1;
}
int main(){
	string a, b, fib[1000] = {"1", "2"};
	for(int i = 2; i < 1000; i++)
		fib[i] = add(fib[i-1], fib[i-2]);
	while(cin >> a >> b){
		if(a == "0" && b == "0")
			break;
		int ct = 0;
		for(int i = 0; i < 1000; i++)
			if(compare(a, fib[i]) <= 0 && compare(b, fib[i]) >= 0)
				ct++;
		cout << ct << "\n";
	}
	return 0;
}
