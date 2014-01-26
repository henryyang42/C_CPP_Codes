#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string add(string a, string b){
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	const int SIZE = 100 + 10;
	int ans[SIZE] = {};
	for(int i = 0; i < a.length(); i++)
		ans[i] += a[i] - '0';
	for(int i = 0; i < b.length(); i++)
		ans[i] += b[i] - '0';
	for(int i = 0; i < SIZE-1; i++)
		ans[i+1] += ans[i] / 10, ans[i] %= 10;
	char ansstr[SIZE] = {};
	ansstr[0] = '0';
	int x = SIZE-1;
	while(x >= 0 && !ans[x])
		x--;
	while(x >= 0)
		ansstr[x] = ans[x--] + '0';
	string ansstring = string(ansstr);
	reverse(ansstring.begin(), ansstring.end());
	return ansstring;
}

int main(){
	string s, t;
	while(cin >> s >> t)
		cout << add(s, t) << "\n";
	return 0;
}
