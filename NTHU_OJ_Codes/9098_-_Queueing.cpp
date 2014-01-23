#include<cstdio>
#include<queue>
#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	queue<string> q;
	while(cin >> s){
		if(s == "Push")
			cin >> s, q.push(s);
		else if(s == "Pop" && !q.empty())
			q.pop();
		else if(s == "Front"){
			if(!q.empty())
				cout << q.front() << endl;
			else
				cout << "empty" << endl;
		}
	}
	return 0;
}
