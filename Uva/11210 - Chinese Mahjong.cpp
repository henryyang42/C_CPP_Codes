#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;
int tile_ct[34], valid, tmp[34], kase;
vector<int> ans;
string tiles[] = {
	"1T", "2T", "3T", "4T", "5T", "6T", "7T", "8T", "9T",
	"1S", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S",
	"1W", "2W", "3W", "4W", "5W", "6W", "7W", "8W", "9W",
	"DONG", "NAN", "XI", "BEI", "ZHONG", "FA", "BAI"
};
int to_int(string &tile){
	for(int i = 0; i < 34; i++)
		if(tile == tiles[i])
			return i;
}
void dfs(int lv){
	if(lv == 5 || valid){
		valid = 1;
		return;
	}
	if(lv == 0){
		for(int i = 0; i < 34; i++){
			if(tmp[i] >= 2){
				tmp[i] -= 2;
				dfs(lv+1);
				tmp[i] += 2;
			}
		}
	}
	else{
		for(int i = 0; i < 34; i++){
			if(tmp[i] >= 3){
				tmp[i] -= 3;
				dfs(lv+1);
				tmp[i] += 3;
			}
			if(i < 27 && i/9 == (i+2)/9 && tmp[i] && tmp[i+1] && tmp[i+2]){
				tmp[i]--, tmp[i+1]--, tmp[i+2]--;
				dfs(lv+1);
				tmp[i]++, tmp[i+1]++, tmp[i+2]++;
			}
		}
	}
}
int main(){
	string tok, str;
	while(getline(cin, str)){
		if(str == "0")
			break;
		memset(tile_ct, 0, sizeof(tile_ct));
		ans.clear();
		stringstream ss(str);
		while(ss >> tok)
			tile_ct[to_int(tok)]++;
		for(int i = 0; i < 34; i++)
			if(tile_ct[i] < 4){
				valid = 0;
				memcpy(tmp, tile_ct, sizeof(tile_ct));
				tmp[i]++;
				dfs(0);
				if(valid)
					ans.push_back(i);
			}
		printf("Case %d: ", ++kase);
		if(ans.size() == 0)
			puts("Not ready");
		else{
			for(int i = 0; i < ans.size(); i++)
				cout << (i ? " " : "") << tiles[ans[i]];
			puts("");
		}
	}
	return 0;
}
