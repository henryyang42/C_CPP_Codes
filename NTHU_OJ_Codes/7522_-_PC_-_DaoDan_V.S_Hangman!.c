#include<stdio.h>

int main(){
    int n, i;
    char ans[1000], test[1000];
    while(scanf("%d", &n) > 0, n + 1){
        int ansct[200] = {0}, testct[200] = {0}, ansnum = 0, wrong = 0;
        printf("Round %d\n", n);
        scanf("%s%s", ans, test);
        for(i = 0;ans[i]; i ++){
            if(ansct[ans[i] ]== 0)
                ansct[ans[i]] = 1, ansnum++;
        }
        int flag = 0;
        for(i = 0; test[i]; i++){
            if(testct[test[i]] == 0){
                testct[test[i]] = 1;
                if(ansct[test[i]] == 1)
                    ansnum--;
                else
                    wrong++;
            }
            if(wrong >= 7){puts("You lose."), flag = 1;break;}
            if(ansnum == 0){puts("You win."), flag = 1;break;}
        }
        if(flag == 0)puts("You chickened out.");
    }
	return 0;
}
