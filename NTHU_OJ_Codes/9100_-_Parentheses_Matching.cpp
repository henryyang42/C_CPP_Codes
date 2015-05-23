#include<stdio.h>
#include<stack>
using namespace std;
int returnvalue(char c){
	switch(c){
		case '{':
			return 1;
		case '[':
			return 2;
		case '(':
			return 3;
		case '<':
			return 4;
		case '}':
			return 5;
		case ']':
			return 6;
		case ')':
			return 7;
		case '>':
			return 8;
		default:
			return 0;
	}
}
int main(){
	int a, i, j, cti = 0;
	char s[10001];
	scanf("%d", &a);
	getchar();
	for(i = 1; i <= a; i++){
		cti++;
		stack<int> S;
		char ct[10001] = {0}, fg = 1, top = 0;
		gets(s);
		j = 0;
		while(s[j]){
			int ret = returnvalue(s[j++]);
			if(ret > 4){
				if(!S.empty() && S.top() != ret-4 || S.empty()){
					fg = 0;
					break;
				}
				S.pop();
			}
			else if(ret && ret <= 4){
				S.push(ret);
			}
		}
		printf("Case %d: ", cti);
		if(fg && S.empty())
			puts("Yes");
		else
			puts("No");
		}
    return 0;
}
