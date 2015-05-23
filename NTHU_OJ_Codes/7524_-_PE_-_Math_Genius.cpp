#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stack>
using namespace std;
/*char s[1000000] = {0};
int prime[1000000] = {0};*/
int main(){
/*	int p, q, primect = 0;
	for(p = 2; p < 1000000; p++)
		if(s[p] == 0)
			prime[primect++] = p;
		else
			for(q = p * p; q < 1000000; q += p)
				s[q] = 1;*/
    char s[10000];
    stack<int> number, power;
    while(gets(s) > 0){
		if(strcmp(s, "0") == 0)
			return 0;
        int num[10000], ct = 0, i;
        for(i = 0; s[i]; i++){
            int j = 0;
            char temp[100] = {0};
            if(isdigit(s[i]))
                while(isdigit(s[i]))
                    temp[j++] = s[i++];
            num[ct++] = atoi(temp);
            if(atoi(temp) == 0)
            	break;
        }
     	int ans = 1;
        for(i = 0; i < ct - 1; i += 2){
            while(num[i + 1] > 0)
                ans *= num[i], num[i+1]--;
        }
        ans--;
        for(i = 2; ans > 1; i++){
            int count = 0;
            while(ans % i == 0 && ans > 1)
                count++, ans /= i;
            if(count > 0)
                number.push(i), power.push(count);
        }
        int flag = 0;
        while(!number.empty()){
            if(flag)
                printf(" %d %d", number.top(), power.top());
            else
                printf("%d %d", number.top(), power.top());
            number.pop(), power.pop();flag++;
        }
        putchar(10);
    }
	return 0;
}
