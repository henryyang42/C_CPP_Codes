#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<vector>
using namespace std;
char s[10001];
vector<char> v[10001];
int len, ind;
void build(int lv, int left) {
	v[lv].push_back(s[ind--]);
	while (left-- && ind >= 0) {
		if (isupper(s[ind]))
			build(lv + 1, 2);
		else
			build(lv + 1, 0);
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		len = strlen(s);
		ind = len - 1;
		for (int i = 0; i <= len; i++)
			v[i].clear();
		build(0, 2);
		for (int i = len; i >= 0; i--)
			for (int j = 0; j < v[i].size(); j++)
				putchar(v[i][j]);
		putchar(10);
	}
	return 0;
}