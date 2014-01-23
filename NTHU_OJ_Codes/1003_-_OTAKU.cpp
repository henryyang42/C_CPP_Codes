#include<iostream>
#include<set>
#include<string>
#include<cstdio>
using namespace std;

int main(){
    int n, m, k;
    scanf("%d%d", &n, &m);
    set<string> S;
    string s;
    while(n--)
        cin >> s, S.insert(s);
    while(m--){
        scanf("%d", &k);
        int ct = 0;
        for(int i = 0; i < k; i++)
            cin >> s, ct += (S.find(s) != S.end());
        if(ct*2 > k)
            puts("Y");
        else
            puts("N");
    }
    return 0;
}
