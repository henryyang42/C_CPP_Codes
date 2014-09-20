#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	int k = 0;
	while(cin >> s){
		if(s == "<br>"){
			k = 0;
			putchar(10);
		}
		else if(s == "<hr>"){
			if(k)
				putchar(10);
			k = 0;
			puts("--------------------------------------------------------------------------------");
		}
		else{
			k += (k ? 1 : 0) + s.length();
			if(k <= 80){
				if(k != s.length())
					putchar(32);
			}
			else{
				putchar(10);
				k = s.length();
			}
			cout << s;
		}
	}
	putchar(10);
	return 0;
}

