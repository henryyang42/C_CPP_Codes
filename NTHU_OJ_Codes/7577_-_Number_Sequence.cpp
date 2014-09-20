#include<stdio.h>
int find_index(long long  s[], int key){
    int upper = 99999, middle, lower = 0;
    while(upper > lower){
        middle = (upper + lower) / 2;
        if(s[middle] > key)
            upper = middle - 1;
        else
            lower = middle + 1;
    }
    while(s[middle] >= key)
        middle--;
    while(s[middle] < key && s[middle+1] < key)
        middle++;
    return middle;
}
int calc(int x){
    int tot = 0;
    if(x >= 10000)
        return 9 + 180 + 2700 + 36000 + 5*(x-9999);
    if(x >= 1000)
        return 9 + 180 + 2700 + 4*(x-999);
    if(x >= 100)
        return 9 + 180 + 3*(x - 99);
    if(x >= 10)
        return 9 + 2*(x - 9);
    return x;
}
long long ans[100000], temp[100000];
int seq(int n){
    int i;
    i = find_index(temp, n);
    n -= temp[i];
    char s[10];
    sprintf(s, "%d", i + 1);
    return s[n - 1] - '0';
}

int main(){
    for(int i = 1; i < 100000; i++)
        temp[i] = calc(i), ans[i] = ans[i - 1] + temp[i];
    int n, i, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        i = find_index(ans, n);
        n -= ans[i];
        printf("%d\n", seq(n));
    }
    return 0;
}
