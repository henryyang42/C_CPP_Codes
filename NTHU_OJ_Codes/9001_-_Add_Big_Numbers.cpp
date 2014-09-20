#include<stdio.h>
#include<string.h>
#define N 200
char s1[N], s2[N], ans[N], ans1[N], ans2[N];
int l1, l2;
int comparebig(char *p1, char *p2){
	if(l2 != l1)
		return l1 - l2;
	else
		return strcmp(p1, p2);
}
void reverse(char *ans, char *p, int l){
	int i;
	for(i = 0; i < l; i++)
		*(ans + l - 1 - i) = *(p + i) - '0';
}
void print(char *p, int l){
	int i;
	for(i = l; i >= 0; i--)
		putchar('0' + *(p + i));
	putchar('\n');	
}
void addBN(int l){
	int i;
	for(i = 0; i < l; i++)
		ans[i] = ans1[i] + ans2[i];
	for(i = 0; i <= l; i++)
		ans[i + 1] += ans[i] / 10, ans[i] %= 10;	
}
void minusBN(char *p1, char *p2, int l){
	int i;
	for(i = 0; i < l; i++)
		ans[i] = *(p1 + i) - *(p2 + i);
	for(i = 0; i < l; i++)
		if(ans[i] < 0)
			ans[i] += 10, ans[i + 1]--;	
}
int main(){
start:
	while(scanf("%s%s",s1,s2)>0){
		memset(ans1, 0, sizeof(ans1));
		memset(ans2, 0, sizeof(ans2));
		memset(ans, 0, sizeof(ans));
		char *p1 = s1, *p2 = s2;
		int l;
		int s1sign = 0, s2sign = 0, com;
		if(s1[0] == '-')
			s1sign = 1, p1++;
		if(s2[0] == '-')
			s2sign = 1, p2++;
		while(*p1 == '0')
			p1++;
		while(*p2 == '0')
			p2++;
		l1 = strlen(p1), l2 = strlen(p2);
		reverse(ans1, p1, l1);
		reverse(ans2, p2, l2);
		com = comparebig(p1, p2);
		if((s1sign + s2sign) % 2 == 0){
			addBN(l1 > l2 ? l1 : l2);
			int l = N - 1;
			while(ans[l] == 0)
				l--;
			if(l < 0){
				puts("0");
				goto start;	
			}
			else{
				if(s1sign + s2sign)
					putchar('-');
				print(ans, l);
			}
		}
		else{
			if(com == 0){
				puts("0");
				goto start;	
			}
			if(s1sign){
				if(com>0)
					putchar('-'), minusBN(ans1, ans2, N / 2);
				else
					minusBN(ans2, ans1, N / 2);
			}
			else{
				
				if(com>0)
					minusBN(ans1, ans2, N / 2);
				else
					putchar('-'), minusBN(ans2, ans1, N / 2);	
			}
			l = N - 1;
			while(ans[l] == 0)
				l--;
			print(ans, l);
		}
	}
    return 0;
}
