#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <cmath>
#define PI 3.141592653589793
#define RAD (180/PI)
#define R 6378.0
using namespace std;

int main() {
    map<string, pair<double, double> > world;
    string s, t;
    while(cin >> s){
		if(s == "#")
			break;
		double alt, lon;
		cin >> alt >> lon;
		world[s] = pair<double, double>(alt, lon);
    }
    int ct = 0;
    while(cin >> s >> t){
		double ans;
		if(s == "#" && t == "#")
			break;
		if(world.find(s) == world.end() || world.find(t) == world.end()){
			cout << s << " - " << t;
			printf("\nUnknown\n");
			putchar(10);
			continue;
		}

		double x1 = R * cos(world[s].first / RAD) * cos(world[s].second / RAD), y1 = R * cos(world[s].first / RAD) * sin(world[s].second / RAD),
		z1 = R* sin(world[s].first / RAD);
		double x2 = R * cos(world[t].first / RAD) * cos(world[t].second / RAD), y2 = R * cos(world[t].first / RAD) * sin(world[t].second / RAD),
		z2 = R* sin(world[t].first / RAD);
		double l = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
		double theta = 2*asin(l/(2*R));
		ans = R * theta;
		cout << s << " - " << t;
		printf("\n%.0lf km\n", ans);
		putchar(10);
    }
    return 0;
}

