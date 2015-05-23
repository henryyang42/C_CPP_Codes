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
int lines[4] = {10 - 3, 50 - 3, 100 - 3, 1000 - 3};
int num_of_char[4] = {1000, 10000, 10000, 1000};
int article_num[4] = {10, 10, 10, 10};
char article[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 -=[];.,+*!@#$^&()";
int len;
char s[10000001];
void print_line(int n) {
	for (int i = 0; i < n; i++) {
		putchar(article[rand() % len]);
	}
	putchar(10);
}
int main(int argc, char *argv[]) {
	len = strlen(article);
	for (int Case = 0; Case < 4; Case++) {
		freopen(out_files[Case], "w", stdout);
		if (Case) {
			freopen(out_files[Case - 1], "r", stdin);
			while (gets(s) > 0)
				puts(s);
		}
		int line;
		for (int i = 0; i < article_num[Case]; i++) {
			line = 1 + rand() % lines[Case];
			printf("%d\n", line);
			while (line--)
				print_line(2 + rand() % num_of_char[Case]);
		}

		//special
		if (Case == 0) {

		}
		if (Case == 1) {

		}
		if (Case == 2) {

		}
		if (Case == 3) {
			int line = 3;
			printf("%d\n", line);
			while (line--) {
				for (int i = 0; i < 10000000 - 1; i++)
					putchar('Z');
				putchar(10);
			}
		}

	}
	return 0;
}