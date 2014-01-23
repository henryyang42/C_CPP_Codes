#include<stdio.h>
#include<string.h>

void reverse_(char s[]){
	int i = 0, j = strlen(s) - 1;
	while(i < j){
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++, j--;
	}
}
int div;int ans[1000] = {0};
void add(int ans[], int s[]){
	int i;
	for(i = 0; i < 300; i++)
		ans[i] += s[i];
}
void divide(int s[]){
	int temp[1000] = {0};
	int i = 201;
	while(i--){
		while(s[i] >= 5 || s[i+1] > 0){
			temp[i]++;
			s[i] -= 5;
			if(s[i] < 0 && s[i+1] > 0) s[i+1]--, s[i] += 10;
		}
	}
	add(ans,temp);
	for(i = 0; i < 300; i++) s[i] += temp[i];
}
int main(){
	char s[1000] = {0};
	while(scanf("%s", s) > 0){
		memset(ans, 0, sizeof(ans));
	int i = 300;div = 1000;
	reverse_(s);
	int ss[1000] = {0};
	for(i = 0; i < 300;i++) if(s[i]) s[i] -= '0', ss[i] = s[i];
	int ct = 100;add(ans, ss);
	while(div--){
		int j = 200;
		while(ss[j] == 0 && j >= 0)j--;
		if(j <= 0 && ss[j] < 5) break;
		divide(ss);
	}

	for(i = 0; i < 300; i++) ans[i+1] += ans[i] / 10, ans[i] %= 10;
	i = 300;
	while(ans[i] == 0) i--;if(i == -1 ) putchar('0');
	while(i >= 0)putchar('0' + ans[i--]);putchar(10);
	memset(s, 0, sizeof(s));
	}
	return 0;
}
