#include<list>
#include<string>
#include<iostream>
using namespace std;
int main(){
	list<string> b, f;
	string s1, now = "http://www.acm.org/";
	while(cin >> s1){
		if(s1 == "BACK")
			if(b.empty())
				cout << "Ignored\n";
			else{
				f.push_front(now);
				now = b.front();
				b.pop_front();
				cout << now << endl;
			}
		else if(s1 == "VISIT")
			b.push_front(now), cin >> now, cout << now << endl, f.clear();
		else if(s1 == "FORWARD")
			if(f.empty())
				cout << "Ignored\n";
			else{
				b.push_front(now);
				now = f.front();
				f.pop_front();
				cout << now << endl;
			}
	}
	return 0;
}
