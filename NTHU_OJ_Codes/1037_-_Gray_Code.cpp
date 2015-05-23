#include<string>
#include<iostream>
#include<vector>
using namespace std;
vector<string> s[12];
int main(){
	s[1].push_back("0");
	s[1].push_back("1");
	for(int i = 2; i <= 11; i++){
		for(int j = 0; j < s[i-1].size(); j++)
			s[i].push_back("0"+s[i-1][j]);
		for(int j = s[i-1].size() - 1; j >= 0; j--)
			s[i].push_back("1"+s[i-1][j]);
	}
	int n;
	while(cin >> n){
		for(int i = 0; i < s[n].size(); i++)
			cout << s[n][i] << "\n";
	}
	return 0;
}
