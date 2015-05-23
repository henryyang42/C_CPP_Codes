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
#define MAX 3200
using namespace std;

char p[MAX];
vector<int> prime;
vector<int> M[100];
int main(int argc, char *argv[]) {
    for (int i = 2; i < MAX; i++) {
        if (!p[i]) {
            prime.push_back(i);
            for (int j = 2 * i; j < MAX; j += i)
                p[j] = 1;
        }
    }
    for (int i = 2; i <= 1e7; i++) {
        int val = i, ct = 0;
        for (int j = 0; prime[j]*prime[j] <= val; j++) {
            int pr = prime[j];
            if (val % pr == 0) {
                ct++;
                while (val % pr == 0)
                    val /= pr;
            }
        }
        if (val > 1)
            ct++;
        M[ct].push_back(i);
    }
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int T, A, B, K;
    cin >> T;
    for (int TT = 1; TT <= T; TT++) {
        cin >> A >> B >> K;
        int ans = 0;
        if (K <= 8) {
            for (int i = 0; i < M[K].size(); i++)
                if (M[K][i] >= A && M[K][i] <= B)
                    ans++;
        }
        printf("Case #%d: %d\n", TT, ans);
    }
    return 0;
}