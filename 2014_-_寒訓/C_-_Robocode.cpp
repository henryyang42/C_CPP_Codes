#include<cstdio>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;

vector<string> cmd[100];
map<string, int> tankname;
typedef struct gg{
	bool alive;
	int angle;
	bool move;
	int x, y;
	void init(){
		alive = true;
		angle = x = y = 0;
		move = false;
	}
	void print(){
		printf("alive: %d, move: %d, (x, y) = (%3d, %3d), angle = %4d\n",
				alive, move, x, y, angle);
	}
}Tank;
typedef struct ggg{
	int x, y, angle;
}Shot;
Shot shot[1001];
int shotct, n, m;
Tank tank[100];
void shoot(int id){
	shot[shotct].angle = tank[id].angle;
	shot[shotct].x = tank[id].x;
	shot[shotct].y = tank[id].y;
	shotct++;
}

void execute(string str){
	stringstream ss;
	ss << str;
	string name, command;
	ss >> name >> command;
	if(command == "SHOOT"){
		if(tank[tankname[name]].alive)
			shoot(tankname[name]);
	}
	else if(command == "MOVE"){
		tank[tankname[name]].move = true;
	}
	else if(command == "STOP"){
		tank[tankname[name]].move = false;
	}
	else if(command == "TURN"){
		int da, angle;
		ss >> da;
		angle = tank[tankname[name]].angle;
		angle = (angle + da +  360) % 360;
		tank[tankname[name]].angle = angle;
	}
}

void detect(){
	for(int i = 0; i < n; i++)
		printf("%d: ", i), tank[i].print();

}

int main(){

	while(scanf("%d%d", &n, &m), n+m){
		tankname.clear();
		shotct = 0;
		for(int i = 0; i < 100; i++)
			cmd[i].clear();
		for(int i = 0; i < n; i++){
			string name;
			int x, y, angle;
			cin >> name >> x >> y >> angle;
			tank[i].init();
			tank[i].x = x, tank[i].y = y, tank[i].angle = angle;
			tankname[name] = i;
		}
		int id;
		string command;
		while(m--){
			cin >> id;
			getline(cin, command);
			cmd[id].push_back(command);
		}
		/*for(int i = 0; i < 10; i++){
			printf("%d: ", i);
			for(int j = 0; j < cmd[i].size(); j++)
				cout << cmd[i][j] << " ; ";
			cout << "\n";
		}*/
		for(int i = 0; i < 7; i++){
			printf("time:%d\n", i);
			for(int j = 0; j < cmd[i].size(); j++)
				execute(cmd[i][j]);
			detect();
		}
	}
	return 0;
}
