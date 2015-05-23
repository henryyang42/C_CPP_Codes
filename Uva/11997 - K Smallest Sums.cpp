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
int s[1000][1000], n;
struct Item {
	int x, ind;
	Item(int a, int b): x(a), ind(b) {}
	bool operator < (const Item &rhs)const {
		return x > rhs.x;
	}
};
void merge_(int A[], int B[], int C[]) {
	priority_queue<Item> q;
	for (int i = 0; i < n; i++)
		q.push(Item(A[i] + B[0], 0));
	for (int i = 0; i < n; i++) {
		int x = q.top().x;
		int ind = q.top().ind;
		q.pop();
		C[i] = x;
		if (ind + 1 < n)
			q.push(Item(x - B[ind] + B[ind + 1], ind + 1));
	}
}
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	while (scanf("%d", &n) > 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				scanf("%d", &s[i][j]);
			sort(s[i], s[i] + n);
		}
		for (int i = 1; i < n; i++)
			merge_(s[0], s[i], s[0]);
		for (int i = 0; i < n; i++) {
			if (i)
				putchar(32);
			printf("%d", s[0][i]);
		}
		putchar(10);
	}
	return 0;
}