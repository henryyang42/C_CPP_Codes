#include<stdio.h>

int main(){
	char s[30][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co"};
	int n;
	while(scanf("%d", &n) > 0)
		puts(s[n-1]);
	return 0;
}
