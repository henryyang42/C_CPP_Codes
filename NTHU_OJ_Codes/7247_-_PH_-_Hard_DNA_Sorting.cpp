#include<stdio.h>
#include<map>
using namespace std;
char s[10001][1000];
int main(){
    int n, m, fg = 0;
    while(scanf("%d%d", &m, &n) > 0){
        for(int i = 0; i < n; i++)
            scanf("%s", s[i]);
        map<int, int> M;
        for(int i = 0; i < n; i++){
            char temp;
            int tot = 0, ct[200] = {0};
            for(int j = 0; j < m; j++){
                tot += ((s[i][j] < 'G') ? ct['G'] : 0) + ((s[i][j] < 'C') ? ct['C'] : 0) + ((s[i][j] < 'T') ? ct['T'] : 0);
                ct[s[i][j]]++;
            }
            M[tot]++;
        }
        if(fg++) putchar(10);
        map<int, int>::iterator it = M.begin();
        while(it != M.end()){
            int ct = it -> second, x = it -> first;
            it++;
            while(ct--)
                printf("%d\n", x);
        }

    }
    return 0;
}
