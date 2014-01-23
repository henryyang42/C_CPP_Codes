#include<iostream>
#include<map>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
string sort_(string s){
	string t = s;
	for(int i = 0; i < t.length(); i++)
		t[i] = tolower(t[i]);
	sort(t.begin(), t.end());
	return t;
}
int main(){
	int n;
	map<string, set<string> > m;
	string s;
	cin >> n;
	while(n--){
		cin >> s;
		m[sort_(s)].insert(s);
	}
	while(cin >> s){
		set<string> *S = &m[sort_(s)];
		for(set<string>::iterator it = S -> begin(); it != S -> end(); it++){
			if(it != S -> begin())
				cout <<",";
			cout << *it;
		}
		cout << "\n";
	}
	return 0;
}
