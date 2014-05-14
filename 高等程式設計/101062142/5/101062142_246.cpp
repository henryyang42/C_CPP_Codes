#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#define DRAW 1
#define WIN 2
#define LOSS 3
using namespace std;
int cycle, c[100], deck[7][100], dct[7], pos, status;
queue<int> card;
set<pair<queue<int>, vector<int> > >S;
int Drop(int pos){
	int len = dct[pos];
	if(len < 3){
		return 0;
	}
	else{
		for(int i = 2; i >= 0; i--){
			int ind[3] = {(len-3+i)%len, (len-2+i)%len, (len-1+i)%len};
			int tot = deck[pos][ind[0]]+deck[pos][ind[1]]+deck[pos][ind[2]];
			sort(ind, ind+3);
			if(tot <= 30 && tot >= 10 && tot % 10 == 0){
				for(int j = 0; j < 3; j++){
					card.push(deck[pos][ind[j]]);
					deck[pos][ind[j]] = 0;
				}
				for(int j = 0; j < dct[pos]; j++)
					deck[pos][j] = deck[pos][j+i];
				dct[pos] -= 3;
				return 1;
			}
		}
	}
	return 0;
}

int repeat(){
	vector<int> v;
	for(int i = 0; i < 7; i++)
		for(int j = 0; j < dct[i]; j++)
			v.push_back(deck[i][j]);
	v.push_back(pos);
	return !S.insert(make_pair(card, v)).second;
}

int main(){
	while(scanf("%d", &c[0]), c[0]){
		for(int i = 1; i < 52; i++)
			scanf("%d", &c[i]);
		cycle = pos = status = 0;
		queue<int> newqueue;
		card = newqueue;
		for(int i = 0; i < 52; i++)
			card.push(c[i]);
		for(int i = 0; i < 7; i++)
			deck[i][dct[i]++] = card.front(), card.pop();
		while(1){
			cycle++;
			while(!dct[pos])
				pos = (pos + 1) % 7;				
			deck[pos][dct[pos]++] = card.front(), card.pop();
			
			while(Drop(pos));
			
			if(card.empty()){
				status = LOSS;
				break;
			}
			int dtot = 0;
			for(int i = 0; i < 7; i++)
				dtot += dct[i];
			if(dtot == 0){
				status = WIN;
				break;
			}

			if(repeat()){
				status = DRAW;
				break;
			}
			pos = (pos + 1) % 7;
		}

		switch(status){
			case WIN:
			printf("Win : %d\n", cycle+7);
			break;

			case LOSS:
			printf("Loss: %d\n", cycle+7);
			break;

			case DRAW:
			printf("Draw: %d\n", cycle+7);
			break;
		}
		memset(c, 0, sizeof(card));
		memset(deck, 0, sizeof(deck));
		memset(dct, 0, sizeof(dct));
		S.clear();
	}
	return 0;
}