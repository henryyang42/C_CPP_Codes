#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int s[7], ans;
	while(scanf("%d", &s[1]) > 0){
		ans = s[1];
		for(int i = 2; i <= 6; i++)
			scanf("%d", &s[i]), ans += s[i];
		if(!ans)
			break;
		ans = s[6] + s[5] + s[4] + s[3] / 4;
		s[3] %= 4;
		s[1] -= 11*s[5];
		s[2] -= 5*s[4];
		if(s[3] == 1)
			ans++, s[2] -= 5, s[1] -=7;
		else if(s[3] == 2)
			ans++, s[2] -= 3, s[1] -= 6;
		else if(s[3] == 3)
			ans++, s[2] -= 1, s[1] -= 5;
		if(s[2] < 0){
            s[1] += 4*s[2];
            s[2] = 0;
        }
        if(s[1] < 0)
            s[1] = 0;
		ans += (s[1] + 4*s[2]) / 36;
        if((s[1]+4*s[2]) % 36 != 0)
            ans++;
		printf("%d\n", ans);
	}
	return 0;
}
