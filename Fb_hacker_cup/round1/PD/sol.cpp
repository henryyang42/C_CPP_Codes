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
#define MAX 200015
struct node {
    node *parent, *child;
    int level, gift;
} *staff[MAX];
vector<node *> levels[MAX];
int main(int argc, char *argv[]) {
    freopen("in.txt", "r", stdin);
    freopen("out", "w", stdout);
    int T, N, parent;
    cin >> T;
    for (int TT = 1; TT <= T; TT++) {
        cin >> N;
        staff[0] = (node *) malloc(sizeof(node));
        staff[0]-> level = 0;
        staff[0]->parent = NULL;
        staff[0]->child = NULL;
        levels[0].push_back(staff[0]);
        scanf("%d", &parent);
        for (int i = 1; i < N; i++) {
            scanf("%d", &parent);
            staff[i] = (node *) malloc(sizeof(node));
            staff[i]->parent = staff[parent - 1];
            staff[i]->parent->child = staff[i];
            staff[i]->level = staff[i]->parent->level + 1;
            staff[i]->child = NULL;
            levels[staff[i]->level].push_back(staff[i]);
        }

        long long ans = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (staff[i]->child == NULL) {
                ans++;
                staff[i]->gift = 1;
                continue;
            }
            int Max, Min, lv;
            lv = staff[i]->level + 1;
            Min = Max = levels[lv][0]->gift;
            for (int j = 0; j < levels[lv].size(); j++) {
                int gift = levels[lv][j]->gift;
                Min = min(Min, gift);
                Max = max(Max, gift);
            }
            if (Min == 1) {
                ans += Max + 1;
                staff[i]->gift = Max + 1;
            }
            else {
                ans++;
                staff[i]->gift = 1;
            }
        }
        printf("Case #%d: %lld\n", TT, ans);
        for (int i = 0; i < N; i++) {
            free(staff[i]);
            levels[i].clear();
        }
    }
    return 0;
}