#include <cstdio>
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
char out_files[10][10] = {"in1", "in2", "in3", "in4"};
char s[100000];
int T[] = {10, 20, 30, 40}, N[] = {10, 20, 20, 30}, M[] = {15, 15, 30, 30};
void genWord(int len) {
	int length = rand() % len + 1;
	int same = rand() % length;
	if (rand() % 2) {
		for (int i = 0; i < same; i++)
			putchar('a');
		for (int i = 0; i < length - same; i++)
			putchar(rand() % 26 + 'a');
	}
	else {
		for (int i = 0; i < length - same; i++)
			putchar(rand() % 26 + 'a');
		for (int i = 0; i < same; i++)
			putchar('a');
	}
}
int main(int argc, char *argv[]) {
	for (int Case = 0; Case < 4; Case++) {
		freopen(out_files[Case], "w", stdout);
		int t = T[Case];
		if (Case) {
			freopen(out_files[Case - 1], "r", stdin);
			scanf("%d", &t);
			getchar();
			t += T[Case];
			printf("%d\n", t);
			while (gets(s) > 0)
				puts(s);
		}
		else {
			printf("%d\n", t);
		}
		for (int i = 0; i < T[Case]; i++) {
			int n = (rand() % N[Case]) + 1;
			printf("%d\n", n);
			for (int j = 0; j < n; j++) {
				if (j)
					putchar(32);
				genWord(M[Case]);
			}
			putchar(10);
		}
		//special
		if (Case == 0) {

		}
		if (Case == 1) {

		}
		if (Case == 2) {

		}
		if (Case == 3) {

		}

	}
	return 0;
}