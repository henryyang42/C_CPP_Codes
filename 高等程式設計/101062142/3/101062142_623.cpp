#include <iostream>
#include <algorithm>
#include <string>
#define MAX 3000
using namespace std;
string mul(string a, int b){
	reverse(a.begin(), a.end());
	char ans[MAX] = {};
	int temp[MAX] = {}, len = a.size() + 4;
	for(int i = 0; i < a.size(); i++)
		temp[i] = (a[i]-'0') * b;
	for(int i = 0; i < MAX-1; i++)
		temp[i+1] += temp[i] / 10, temp[i] %= 10;
	while(!temp[len])
		len--;
	for(int i = 0; i <= len; i++)
		ans[i] = temp[i] + '0';
	reverse(ans, ans + len+1);
	return string(ans);
} 
int main(){
	int n;
	string ans[1001] = {"1"};
	for(int i = 1; i < 1001; i++)
		ans[i] = mul(ans[i-1], i);
	while(cin >> n){
		cout << n << "!\n" << ans[n] << "\n";
	}
	return 0;
}