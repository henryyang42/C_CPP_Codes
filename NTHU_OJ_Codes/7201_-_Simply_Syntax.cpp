#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stack>
using namespace std;
int main(){
	char s[1000];
	while(scanf("%s", s) > 0){
		int l = strlen(s) - 1, ans = 1;
		stack<char> t;
		while(l >= 0 && ans){
			if(islower(s[l]))
				t.push(s[l]);
			if(s[l] == 'N')
				if( !(!t.empty() && islower(t.top())) )
					ans = 0;
			if(s[l] == 'C' || s[l] == 'D' || s[l] == 'E' || s[l] == 'I'){
				char c1, c2;
				if(!t.empty())
					c1 = t.top(), t.pop();
				else
					ans = 0;
				if(!t.empty())
					c2 = t.top(), t.pop();
				else
					ans = 0;
				if(ans)
					t.push(c1);
			}
			l--;		
		}
		if(t.size() != 1)
			ans = 0;
		puts(ans ? "YES" : "NO");
	}
	return 0;
}
