#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
char s[10000001];
bool cmp(pair<long long, char> const &a, pair<long long, char> const &b)  {
	return a.first != b.first ? (a.first > b.first) : (a.second < b.second);
}
char in_files[10][10] = {"in1", "in2", "in3", "in4"};
char out_files[10][10] = {"out1", "out2", "out3", "out4"};
int n;
#define GEN

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
int pre(string &a, string &b) {
	int ans = 0, len = min(a.length(), b.length());
	for (int i = 1; i <= len; i++) {
		if (a.substr(0, i) == b.substr(b.length() - i, i))
			ans = max(ans, i);
		if (b.substr(0, i) == a.substr(a.length() - i, i))
			ans = max(ans, i);
	}
	return ans;
}
int main() {
#ifdef GEN
	for (int x = 0; x < 4; x++) {
		freopen(in_files[x], "r", stdin);
		freopen(out_files[x], "w", stdout);
#endif

		int t;
		cin >> t;
		while (t--) {
			int n;
			cin >> n;
			map<string, int> ct1, ct2;
			string str[100];
			for (int i = 0; i < n; i++) {
				cin >> str[i];
			}
			int ans = 0;
			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++)
					ans = max(ans, pre(str[i], str[j]));
			printf("%d\n", ans);
		}
#ifdef GEN
	}
#endif

	return 0;
}