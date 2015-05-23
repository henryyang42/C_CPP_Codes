#include<stdio.h>
#include<math.h>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class node {
public:
    int level;
    node *parent;
    node *child;
    int child_ct;
    int gift;
    ~node() {
        level = 0;
        parent = NULL;
        child = NULL;
    }
};

int main() {
    //freopen("in", "r", stdin);
    int ii, tt;
    cin >> ii;
    for (tt = 1; tt <= ii; tt++)
    {

        node *employee[200005];
        vector<node *>levels[200005];
        int tot, ans = 0;
        cin >> tot;

        node *f = new node();
        f->level = 0;
        f->child_ct = 0;
        employee[0] = f;
        levels[0].push_back(f);
        int p; cin >> p;
        for (int i = 1; i < tot; i++) {
            int ma;
            cin >> ma;
            node *tmp = new node();
            tmp->parent = employee[ma - 1];
            tmp->parent->child = tmp;
            tmp->child_ct = 0;
            tmp->level = tmp->parent->level + 1;
            levels[tmp->level].push_back(tmp);
            //           tmp->parent->child_ct++;

            employee[i] = tmp;
        }
        for (int i = tot - 1; i > -1; i--) {

            if (employee[i]->child == NULL) {
                ans++;
                employee[i]->gift = 1;

                continue;
            }
            int max = levels[employee[i]->level + 1][0]->gift;
            int min = levels[employee[i]->level + 1][0]->gift;
            for (int it = 0 ; it != levels[employee[i]->level + 1].size(); ++it) {

                if (levels[employee[i]->level + 1][it]->gift == 1)
                    min = 1;
                if (levels[employee[i]->level + 1][it]->gift > max)
                    max = levels[employee[i]->level + 1][it]->gift;
            }
            if (min != 1) {
                ans++;
                employee[i]->gift = 1;

            }
            else {
                ans += max + 1;
                employee[i]->gift = max + 1;

            }

        }

        cout << "Case #" << tt << ": " << ans << endl;
        for (int i = 0; i < tot; i++) {
            delete(employee[i]);
            employee[i] = NULL;
            levels[i].erase(levels[i].begin(), levels[i].end());
        }

    }
    return 0;
}
