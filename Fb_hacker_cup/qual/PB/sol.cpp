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

int main(int argc, char *argv[]) {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    cin >> t;
    for (int T = 1; T <= t; T++) {
        int n, targ[3], s[100][3], ans = 0;
        for (int i = 0; i < 3; i++)
            cin >> targ[i];
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
                cin >> s[i][j];
        for (int i = 0; i < 1 << n; i++) {
            int temp[3] = {0};
            for (int j = 0; j < n; j++)
                if ((i >> j) & 1) {
                    for (int k = 0; k < 3; k++) {
                        temp[k] += s[j][k];
                    }
                }
            ans |= targ[0] == temp[0] && targ[1] == temp[1] && targ[2] == temp[2];
        }
        printf("Case #%d: %s\n", T, ans ? "yes" : "no");
    }
    return 0;
}