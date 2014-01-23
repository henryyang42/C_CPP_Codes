#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(){
	string s;
	int x;
	priority_queue<int> q;
	while(cin >> s){
		if(s == "PUSH")
			cin >> x, q.push(x);
		else if(s == "POP")
			q.pop();
		else{
			if(!q.empty())
				cout << q.top() << endl;
			else
				cout << "Null" << endl;
		}
	}
	return 0;
}
