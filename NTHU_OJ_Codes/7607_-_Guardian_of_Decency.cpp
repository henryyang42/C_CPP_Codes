#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<iostream>
#define pos(i,j) ((i-1)*w+j)
using namespace std;
vector<int> v[503];
int match[503], matchx[503], vis[503], n, t, p, ct;
struct person{
	int h;
	string sex, music, sport;
}s[503];
bool bi(int x){
	for(int i = 0; i < v[x].size(); i++){
		int y = v[x][i];
		if(!vis[y]){
			vis[y] = 1;
			if(!match[y] || bi(match[y])){
				match[y] = x;
				matchx[x]=1;
				return true;
			}
		}
	}
	return false;
}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			cin >> s[i].h >> s[i].sex >> s[i].music >> s[i].sport;
		p = 0;
		for(int i = 1; i <= n; i++){
			v[i].clear();
			if(s[i].sex == "F")
			for(int j = 1; j <= n; j++)
				if(abs(s[i].h-s[j].h) <= 40 && s[i].sex != s[j].sex && s[i].music == s[j].music && s[i].sport != s[j].sport)
					v[i].push_back(j);
		}
		memset(match, 0, sizeof(match));
		for(int i = 1; i <= n; i++)
			if(v[i].size()){
				memset(vis, 0, sizeof(vis));
				bi(i);
			}
		for(int i = 1; i <= n; i++)
			p += match[i] > 0;
		printf("%d\n", n-p);
	}
	return 0;
}
