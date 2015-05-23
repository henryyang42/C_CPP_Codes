#include<map>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
long long hash(string s){
	long long ans = 0;
	sort(s.begin(), s.end());
	for(int i = 0; i < s.length(); i++)
		ans = ans * 27 + s[i] - 'a' + 1;
	return ans;
}
long long to_longlong(string s){
	long long ans = 0;
	for(int i = 0; i < s.length(); i++)
		ans = ans * 27 + s[i] - 'a' + 1;
	return ans;
}
string to_string(long long x){
	char s[10];
	int i;
	for(i = 0; x > 0; i++)
		( s[i] =x % 27 + 'a' - 1), x /= 27;
	s[i] = 0;
	string ss(s, strlen(s));
	reverse(ss.begin(), ss.end());
	return ss;
}
int main(){
	int n, q;
	string s, temp;
	long long hash_temp;
	map<long long, int> mct;
	map<long long, map<long long, int> > m[27*27+1];
	map<long long, int>::iterator smallest, biggest;
	map<long long, int> *ptr;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		hash_temp = hash(s);
		if(mct[hash_temp] == 0){
			map<long long, int> newone;
			m[27*(s[0]-'a'+1) + s[s.length()-1] - 'a'+1][hash_temp] = newone;
		}

		m[27*(s[0]-'a'+1) + s[s.length()-1] - 'a'+1][hash_temp][to_longlong(s)] = 1;
		mct[hash_temp]++;
	}
	cin >> q;
	while(q--){
		cin >> s;
		if(s.length() > 9){
			cout << "0";
		}
		else{
			ptr = &m[27*(s[0]-'a'+1) + s[s.length()-1] - 'a'+1][hash(s)];
			if(ptr -> empty())
				cout << "0";
			else{
				smallest = ptr -> begin();
				biggest = ptr -> end();
				biggest--;
				cout << ptr -> size() << " "
				<< to_string(smallest -> first) << " "
				<< to_string(biggest -> first);
			}
		}
		cout << "\n";
	}
	return 0;
}
