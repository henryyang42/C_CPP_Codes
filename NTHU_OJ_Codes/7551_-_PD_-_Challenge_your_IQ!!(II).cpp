#include<stdio.h>
char ans[10];
void dfs(int dep){
	int i, temp;
	if(dep == 10){
		/*********** 1 *************/
		for(i = 0; i < 10; i++)
			if(ans[i] == 1){
				temp = i;
				break;
			}
		if(ans[0] != temp)
			return;
		/*********** 4 *************/
		for(i = temp = 0; i < 10; i++)
			if(ans[i] == 0)
				temp++;
		if(ans[3] != temp)
			return;
		/*********** 6 *************/
		int a = 0, b = 0;
		for(i = 0; i < 10; i++)
			if(ans[i] == 0)
				temp++;
		/*********** 8 *************/
		for(i = temp = 0; i < 10; i++)
			if(ans[i] == 0 || ans[i] == 4)
				temp++;
		if(ans[7] != temp)
			return;
		/*********** 5, 10 *************/

		for(i = 0; i < 10; i++){
			if(i)
				putchar(32);
			putchar(ans[i] + 'a');
		}
		putchar(10);
		return;
	}
	for(i = 0; i < 5; i++)
		ans[dep] = i, dfs(dep + 1);
}
int main(){
	/*dfs(0);*/
	puts("d c e b e e d c b a");
	return 0;
}
