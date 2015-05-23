#include<string>
#include<iostream>
#include<map>
#include<cctype>
#include<cstdio>
using namespace std;

int main(){
	int n;
	map<char, double> m;
	m['C'] = 12.01;
	m['O'] = 16.00;
	m['H'] = 1.008;
	m['N'] = 14.01;
	cin >> n;
	while(n--){
		char last;
		string s;
		cin >> s;
		double ans = 0;
		for(int i = 0; i < s.length(); i++){
			if(isalpha(s[i]))
				ans += m[s[i]], last = s[i];
			else{
				int x = 0;
				while(i < s.length() && isdigit(s[i]))
					x = x*10 + s[i++] - '0';
				ans += (x-1)*m[last];
				i--;
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
