#include<stdio.h>
#include<algorithm>
using namespace std;
int stone[500010], L, N, M;

bool  across( int  l)
{
    if(l * M < L)
		return false;
    int  step = 0 , cur = 0;
    for ( int  i=0;i<=N;)
    {
        if (++step>M || stone[i]-cur>l)
            return  false ;
        while (i<=N && stone[i]-cur<=l)
            i++;
        cur = stone[i-1];
    }
    return  true ;
}
int main(){
	while(~scanf("%d%d%d", &L, &N, &M)){
		for(int i = 0; i < N; i++)
			scanf("%d", &stone[i]);
		stone[N] = L;
		sort(stone, stone + N);

        int  l = 0, r = L;
        while (l < r)
        {
            int  mid = (l+r)/2;
            if (across(mid))
                r = mid;
            else
                l = mid+1;
        }
        printf( "%d\n" ,r);
	}
	return 0;
}
