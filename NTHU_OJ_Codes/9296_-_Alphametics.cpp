#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
char n1[100], n2[100], n3[100];
char used[100], visit[10];
int usedct, standard[200];
long long ans;
long long int convert(char s[]){
	long long int value = 0;
	if(standard[s[0]] == 0 && strlen(s) > 1)
		return 214748364700000000LL;
	for(int i = 0; s[i]; i++)
		value = value * 10 + standard[s[i]];
	return value;
}
void dfs(int dep){
	if(dep == usedct){
		long long int a = convert(n1), b = convert(n2), c = convert(n3);
		if(a + b == c && c < ans)
			ans = c;
		return;
	}
	for(int i = 0; i < 10; i++)
		if(!visit[i]){
			visit[i] = 1;
			standard[used[dep]] = i;
			dfs(dep + 1);
			visit[i] = 0;
		}
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		map<char, int> charused;
		scanf("%s%s%s", n1, n2, n3);
		for(int i = 0; n1[i]; i++)
			charused[n1[i]] = 1;
		for(int i = 0; n2[i]; i++)
			charused[n2[i]] = 1;
		for(int i = 0; n3[i]; i++)
			charused[n3[i]] = 1;
		usedct = 0;
		map<char, int>:: iterator it = charused.begin();
		while(it != charused.end())
			used[usedct++] = it -> first, it++;
		for(int i = 0; i < 10; i++)
			visit[i] = 0;
		ans = 21474836470000LL;
		dfs(0);
		printf("%lld\n", ans);
	}
	return 0;
}
