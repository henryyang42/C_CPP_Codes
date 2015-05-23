#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int fre[10000];
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	string str;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	while (cin >> str) {
		if (str == "#")
			break;
		int id, t;
		cin >> id >> t;
		q.push(make_pair(t, id));
		fre[id] = t;
	}
	int k;
	cin >> k;
	while (k--) {
		int id = q.top().second;
		int t = q.top().first;
		q.pop();
		printf("%d\n", id);
		q.push(make_pair(t + fre[id], id));
	}
	return 0;
}