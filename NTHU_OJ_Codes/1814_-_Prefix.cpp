#include<stdio.h>
#include<string>
#include<sstream>
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
struct XDD{
	string xd;
	int num;
}XD;
string str, tok[1000];
bool isoperator(string &str){
	string op[] = {"+", "-", "*"};
	for(int i = 0; i < 3; i++)
		if(op[i] == str)
			return true;
	return false;
}
int calc(int a, string &op, int b){
	if(op == "+")
		return a + b;
	if(op == "-")
		return a - b;
	if(op == "*")
		return a * b;
}
int main(){
	int fg = 0, t;
	scanf("%d", &t);
	getchar();
	while(getline(cin, str)){
		int ct = 0;
		stringstream ss;
		ss << str;
		while(ss >> tok[ct++]);
		vector<XDD> v;
		for(int i = 0; i < ct; i++){
			XD.xd = tok[i];
			if(!isoperator(tok[i]))
				XD.num = atoi(tok[i].c_str());
			v.push_back(XD);
			while(v.size() > 2 && !isoperator(v[v.size()-1].xd) && !isoperator(v[v.size()-2].xd) && isoperator(v[v.size()-3].xd)){
				XD.xd = "(" + v[v.size()-2].xd + v[v.size()-3].xd +v[v.size()-1].xd+")";
				XD.num = calc(v[v.size()-2].num, v[v.size()-3].xd, v[v.size()-1].num);
				for(int k = 0; k < 3; k++)
					v.erase(v.end() - 1);
				v.push_back(XD);
			}
		}
		printf("CASE %d:\n%s=%d\n", ++fg, v[0].xd.c_str(), v[0].num);
	}
	return 0;
}

