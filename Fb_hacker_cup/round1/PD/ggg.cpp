#include<stdio.h>
#include<math.h>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class node {
public:
    int rank;
    node *parent;
    node *child;
    int cn;
    int mon;
    ~node() {
        rank = 0;
        parent = NULL;
        child = NULL;
    }
};

int main() {
    //freopen("/Users/saintni/Desktop/fb/corporate_gifting.txt", "r", stdin);
    //freopen("/Users/saintni/Desktop/fb/o.txt", "w", stdout);

    int ii, tt;
    cin >> ii;
    for (tt = 1; tt <= ii; tt++)
    {

        node *employee[200005];
        vector<node *>ranker[200005];
        int tot, ans = 0;
        cin >> tot;
        int r1 = 0;
        int r2 = 0;
        node *f = new node();
        f->rank = 0;
        f->cn = 0;
        employee[0] = f;
        employee[1] = f;
        ranker[0].push_back(f);
        r1++;
        int p; cin >> p;
        for (int i = 1; i < tot; i++) {
            int ma;
            cin >> ma;
            node *tmp = new node();
            tmp->parent = employee[ma - 1];
            tmp->parent->child = tmp;
            tmp->cn = 0;
            tmp->rank = tmp->parent->rank + 1;
            ranker[tmp->rank].push_back(tmp);
            tmp->parent->cn++;
            //cout<<(tmp->child==0x0)<<endl;

            //cout<<"ma:"<<ma<<"    rank:"<<tmp->rank<<"   employee[ma]->rank:  "<<employee[ma]->rank<<"   tmp->parent->rank:  "<<tmp->parent->rank<<endl;
            if (tmp->rank % 2 == 0)
                r1++;
            else
                r2++;
            employee[i] = tmp;
        }
        for (int i = tot - 1; i > -1; i--) {
            //cout<<"I: "<<i<<"  child: "<<employee[i]->child<<endl;
            if (employee[i]->child == 0x0) {
                ans++;
                employee[i]->mon = 1;
                //  cout<<"i:"<<i<<"  lmon:"<<employee[i]->mon<<endl;
                continue;
            }
            int max = ranker[employee[i]->rank + 1][0]->mon;
            int min = ranker[employee[i]->rank + 1][0]->mon;
            for (int it = 0 ; it != ranker[employee[i]->rank + 1].size(); ++it) {
                //cout<<"i:"<<i<<"  ranker[employee[i]->rank+1][it].mon:"<<ranker[employee[i]->rank+1][it]->mon<<endl;
                if (ranker[employee[i]->rank + 1][it]->mon == 1)
                    min = 1;
                if (ranker[employee[i]->rank + 1][it]->mon > max)
                    max = ranker[employee[i]->rank + 1][it]->mon;
            }
            if (min != 1) {
                ans++;
                employee[i]->mon = 1;
                //  cout<<"i:"<<i<<"  lmon:"<<employee[i]->mon<<"   min:"<<min<<endl;
            }
            else {
                ans += max + 1;
                employee[i]->mon = max + 1;
                // cout<<"i:"<<i<<"  mon:"<<employee[i]->mon<<endl;
            }

        }

        //        if(r1>r2){
        //            ans=r1+r2*2;
        //        }
        //        else
        //            ans=r1*2+r2;
        cout << "Case #" << tt << ": " << ans << endl;
        for (int i = 0; i < tot; i++) {
            delete(employee[i]);
            employee[i] = NULL;
            ranker[i].erase(ranker[i].begin(), ranker[i].end());
        }

    }
    return 0;
}
