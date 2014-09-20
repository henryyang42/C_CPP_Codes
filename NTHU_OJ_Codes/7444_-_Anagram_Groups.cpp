#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
using namespace std;
bool cmp(set<string> const &s1,  set<string> const &s2){
	if(s1.size() != s2.size())
		return s1.size() > s2.size();
	return *s1.begin() < *s2.begin();
}
int main(){
	string s, t;
	map<string, set<string> > m;
	map<string, set<string> >::iterator it;
	vector<set<string> >v;
	v.clear();
	m.clear();
	while(cin >> s){
		t = s;
		sort(t.begin(), t.end());
		m[t].insert(s);
	}
	it = m.begin();
	while(it != m.end())
		v.push_back(it -> second), it++;
	sort(v.begin(), v.end(), cmp);
	for(int i = 0; i < (v.size() > 5 ? 5 : v.size()); i++){
		cout << "Group of size " << v[i].size() <<": ";
		set<string>::iterator it = v[i].begin();
		while(it != v[i].end())
			cout << *it << " ", it++;
		cout << ".\n";
	}
	return 0;
}
