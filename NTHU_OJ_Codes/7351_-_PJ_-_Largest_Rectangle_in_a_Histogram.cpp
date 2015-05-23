#include<stdio.h>
#include<stack>
using namespace std;
int main(){
	int n;
	while(scanf("%d", &n) > 0, n){
		n++;
		stack<long long int> ind, h;
		long long int height, index = 0, minh = 10000000000LL, minind = 1, max = 0, indtop;
		while(n--){
			if(n)
				scanf("%lld", &height);
			else
				height = 0;
			if(height < minh)
				minh = height;
			index++;
			if(ind.empty() || h.top() < height)
				ind.push(index), h.push(height);
			if(h.top() > height){
				long long int temp;
				while(!ind.empty() && h.top() > height){
					indtop = ind.top();
					temp = (index - ind.top()) * h.top();
					if(temp > max)
						max = temp;
					ind.pop(), h.pop();
				}			
				ind.push(indtop),h.push(height); 	
			}
		}
		printf("%lld\n", max);	
	}
	return 0;
}
