#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <cctype>
#include <map>
using namespace std;

int main(){
	
	string charset = "A	.-	J	.---	S	...	1	.----	.	.-.-.-	:	---... \
	B	-...	K	-.-	T	-	2	..---	,	--..--	;	-.-.-. \
	C	-.-.	L	.-..	U	..-	3	...--	?	..--..	=	-...- \
	D	-..	M	--	V	...-	4	....-	'	.----.	+	.-.-. \
	E	.	N	-.	W	.--	5	.....	!	-.-.-- -	-....- \
	F	..-.	O	---	X	-..-	6	-....	/	-..-.	_	..--.- \
	G	--.	P	.--.	Y	-.--	7	--...	(	-.--.	\"	.-..-. \
	H	....	Q	--.-	Z	--..	8	---..	)	-.--.-	@	.--.-. \
	I	..	R	.-.	0	-----	9	----.	&	.-...";
	stringstream ss;
	ss << charset;
	string a, b;
	map<string, string> m;
	while(ss >> a >> b)
		m[b] = a;
	int t, casect = 0;
	char s[10000];
	scanf("%d", &t);
	getchar();
	while(t--){
		gets(s);
		int len = strlen(s);
		printf("Message #%d\n", ++casect);
		for (int i = 0; i < len; ++i){
			char temp[10] = {}, ct = 0;
			if(s[i] == ' '){
				putchar(32);
			}
			else{
				while(s[i] != ' ' && i < len)
					temp[ct++] = s[i++];
				cout << m[string(temp)];
			}
		}
		putchar(10);
		if(t)
			putchar(10);
	}
	return 0;
}
