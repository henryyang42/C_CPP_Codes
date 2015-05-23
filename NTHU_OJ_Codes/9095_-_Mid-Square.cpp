#include<stdio.h>
#include<map>
#define HASH 65536
using namespace std;
unsigned int hash_f(unsigned int Key){
	unsigned long long key = Key;
	key = key * key;
	key >>= 8, key %= HASH;
	return key;
}
map<unsigned int, char> m[HASH];
map<unsigned int, char>::iterator it;
int main(){
	char op[10];
	unsigned int key, hash_value;
	while(scanf("%s", op) > 0){
		if(op[0] == 'I'){
			scanf("%u", &key);
			m[hash_f(key)][key] = 1;
		}
		else if(op[0] == 'P'){
			scanf("%u", &key);
			if(m[hash_value = hash_f(key)].empty() || m[hash_value].find(key) == m[hash_value].end())
				printf("Null");
			else{
				it = m[hash_value].begin();
				printf("%u", it -> first);
				it++;
				while(it != m[hash_value].end())
					printf(" %u", it -> first), it++;
			}
			putchar(10);
		}
		else if(op[0] == 'D'){
			scanf("%u", &key);
			hash_value = hash_f(key);
			m[hash_value].erase(key);
		}
	}
	return 0;
}
