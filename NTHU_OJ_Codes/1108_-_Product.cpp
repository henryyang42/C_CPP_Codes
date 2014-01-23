#include<stdio.h>
#include<string.h>
int main(){
	char s1[1000], s2[1000], temp;
	while(scanf("%s%s", s1, s2) > 0){
		int ans[1000] = {0}, l1 = strlen(s1), l2 = strlen(s2), i, j;
		for(i = 0, j = l1 - 1; i < j; i++, j--)
			temp = s1[i], s1[i] = s1[j], s1[j] = temp;
		for(i = 0, j = l2 - 1; i < j; i++, j--)
			temp = s2[i], s2[i] = s2[j], s2[j] = temp;
		for(i = 0; i < l1; i++)
			for(j = 0; j < l2; j++)
				ans[i + j] += (s1[i] - 48) * (s2[j] - 48);
		for(i = 0; i < 1000; i++)
			ans[i+1] += ans[i] / 10, ans[i] %= 10;
		i = 999;
		while(ans[i] == 0)
			i--;
		if(i < 0)
			putchar('0');
		else
			while(i >= 0)
				putchar(48 + ans[i--]);
		putchar(10);
	}
	return 0;
}
