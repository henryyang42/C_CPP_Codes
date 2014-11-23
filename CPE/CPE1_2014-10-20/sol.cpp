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
//#define GEN
int main(int argc, char *argv[]) {
#ifdef GEN
	for (int x = 0; x < 4; x++) {
		freopen(in_files[x], "r", stdin);
		freopen(out_files[x], "w", stdout);
#endif
		while (scanf("%d", &n) > 0) {
			getchar();
			long long ct[500] = {0};
			while (n--) {
				gets(s);
				int len = strlen(s);
				for (int i = 0; i < len; i++)
					if (isalpha(s[i]))
						ct[s[i]]++;
			}
			vector<pair<long long, char> > v;
			for (int i = 0; i <= 256; i++)
				if (ct[i]) {
					int cost = islower(i) ? i - 'a' + 1 : (i - 'A' + 1) * (i - 'A' + 1);
					v.push_back(make_pair(ct[i] * cost, i));
				}
			sort(v.begin(), v.end(), cmp);
			for (int i = 0; i < v.size(); i++)
				printf("%c %lld\n", v[i].second, v[i].first);
			putchar(10);
		}
#ifdef GEN
	}
#endif
	return 0;
}