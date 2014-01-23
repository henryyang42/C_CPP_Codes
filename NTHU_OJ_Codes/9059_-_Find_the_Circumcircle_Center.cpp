#include<stdio.h>

int main(){
    double  x, y, c1, c2, dx1, dy1, dx2, dy2, x1, x2, x3, y1, y2, y3;
    while(scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3) > 0){
        dx1 = x1 - x2, dy1 = y1 - y2;
        dx2 = x2 - x3, dy2 = y2 - y3;
        c1 = dx1*(x1+x2)/2 + dy1*(y1+y2)/2;
        c2 = dx2*(x2+x3)/2 + dy2*(y2+y3)/2;
        x = c1*dy2 - c2*dy1;
        y = dx1*c2 - dx2*c1;
        x /= (dx1*dy2 - dx2*dy1), y/= (dx1*dy2 - dx2*dy1);
        int X = x, Y = y;
        if((double)X == x && (double)Y == y)
            printf("%d %d\n", X, Y);
        else
            puts("-1");
    }
    return 0;
}
