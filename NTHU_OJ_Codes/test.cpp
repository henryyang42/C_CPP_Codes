#include <cstdio>
#include <cstdlib>
int main(void){
    int n;
    //
    scanf("%d", &n);
    while(n--){
		int ct[256] = {}, ans = 0;
		char s[100];
		scanf("%s", s);
		for(int i = 0; s[i]; i++)
			ct[s[i]]++;
    	for(int i = 0; i < 26; i++)
    		ans += abs(ct['A'+i]-ct['a'+i]);
		printf("%d\n", ans);
    }
    return 0;
}
