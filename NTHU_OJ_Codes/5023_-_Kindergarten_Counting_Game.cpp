#include<iostream>
#include<string>
#include<sstream>
#include<cctype>
using namespace std;
int main(){
	string s;/*let's test how slow c++ io is and how easily I get WA*/
	while(getline(cin, s)){
			int ans = 0;
			for(int i = 0; i < s.length(); i++)
				if(isalpha(s[i])){
					while(isalpha(s[i++]));
					ans++;
					i--;
				}
			cout << ans << '\n';
	}
	return 0;
}
