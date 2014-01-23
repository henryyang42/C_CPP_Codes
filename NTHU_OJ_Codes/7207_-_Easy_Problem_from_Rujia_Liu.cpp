#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
using namespace std;
#define  MAX 1000001
int ct[MAX];
string getstring(int x, int ct){
	string s = "";
	char temp[100] = {0};
	sprintf(temp, "%d %d", x, ct);
	s = temp;
	return s;
}
int main(){
	int n, m, x, i, k, v;
	while(scanf("%d%d", &n, &m) > 0){
		map<string, int> M;
		for(i = 0; i < n; i++){
			scanf("%d", &x);
			ct[x]++;
			string s = getstring(x, ct[x]);
			M[s] = i + 1;
		}
		for(i = 0; i < m; i++){
			scanf("%d%d", &k, &v);
			string s = getstring(v, k);
			if(M.find(s) != M.end())
				printf("%d\n", M[s]);
			else
				puts("0");
		}
	}
	return 0;
}
