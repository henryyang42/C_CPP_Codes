#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, d;
vector<int> l[100];
struct Box{
	int s[11], id;
}box[101];
bool operator < (const Box &a, const Box &b){
	int i = 0;
	while(i < d && a.s[i] == b.s[i]) i++;
	return a.s[i] < b.s[i];
}
bool nested(Box &a, Box &b){
	int i = 0;
	while(i < d && a.s[i] < b.s[i]) i++;
	return i == d;
}
int main(){
	while(scanf("%d%d", &n, &d) > 0){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < d; j++)
				scanf("%d", &box[i].s[j]);
				box[i].id = i + 1;
			sort(box[i].s, box[i].s + d);
		}
		sort(box, box + n);
		int dp[101], Max = 1;
		for(int i = 0; i < n; i++)
			dp[i] = 1, l[i].clear(), l[i].push_back(box[i].id);
		for(int i = 1; i < n; i++)
			for(int j = 0; j < i; j++)
				if(nested(box[j], box[i]) && dp[i] < dp[j] + 1){
					dp[i] = dp[j] + 1, l[i] = l[j], l[i].push_back(box[i].id);
				}
		for(int i = 0; i < n; i++)
			Max = max(Max, dp[i]);
		printf("%d\n", Max);
		for(int i = 0; i < n; i++)
			if(dp[i] == Max){
				printf("%d", l[i][0]);
				for(int j = 1; j < l[i].size(); j++)
					printf(" %d", l[i][j]);
				break;
			}
		putchar(10);
	}
	return 0;
}
