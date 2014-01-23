#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct birth{
	string name;
	int y, m, d;
	bool operator < (const birth &x) const{
		if(y - x.y)
			return y - x.y > 0;
		if(m - x.m)
			return m - x.m > 0;
		if(d - x.d)
			return d - x.d > 0;
	}
}s[100];
int main(){
	int n;
	while(cin >> n){
		for(int i = 0; i < n; i++)
			cin >> s[i].name >> s[i].d >> s[i].m >> s[i].y;
		sort(s, s + n);
		cout << s[0].name << "\n" << s[n-1].name << "\n";
	}
	return 0;
}
