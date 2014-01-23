#include<stdio.h>
int s[100000], n, q, ct;
int find_index(int x){
	int mid, high = ct - 1, low = 0;
	while(high > low){
		mid = (high + low) / 2;
		if(x > s[mid])
			low = mid + 1;
		else if(x < s[mid])
			high = mid - 1;
		else if(x == s[mid])
			break;
	}
	mid = (high + low) / 2;
	return mid;
}
int main(){
	int x, pos, temp;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &x);
		s[ct++] = x;
		if(ct - 1 && s[ct-2] == x)
			ct--;
	}
	scanf("%d", &q);
	while(q--){
		scanf("%d", &x);
		pos = find_index(x);
		temp = pos;
		while(s[temp] >= x && temp >= 0)
			temp--;
		if(temp < 0 || s[temp] == x)
			printf("X ");
		else
			printf("%d ", s[temp]);
		temp = pos;
		while(s[temp] <= x && temp < ct)
			temp++;
		if(temp >= ct || s[temp] == x)
			puts("X");
		else
			printf("%d\n", s[temp]);
	}
	return 0;
}
