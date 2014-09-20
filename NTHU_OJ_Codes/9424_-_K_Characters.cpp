#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int len, k;
char s[101], t[101];
void dfs(int from, int lv){
	if(lv == k){
		t[k] = 0;
		puts(t);
		return;
	}
	for(int i = from; i < len; i++){
		if(t[lv] != s[i]){
			t[lv] = s[i];
			dfs(i+1, lv+1);
		}
	}
	t[lv] = 0;
}

int main(){
	int n;
	string str;
	scanf("%d", &n);
	while(n--){
		cin >> str >> k;
		sort(str.begin(), str.end());
		len = str.length();
		for(int i = 0; i < len; i++)
			s[i] = str[i];
		s[len] = 0;
		memset(t, 0, sizeof(t));
		dfs(0, 0);
		putchar(10);
	}
	return 0;
}
