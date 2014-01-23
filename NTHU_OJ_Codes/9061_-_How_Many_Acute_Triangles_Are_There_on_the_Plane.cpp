#include<cstdio>
#include<cmath>
#define TYPE int
typedef struct vec{
	TYPE x, y;
	vec(TYPE _x=0, TYPE _y=0){
		x = _x, y = _y;
	}
}Vector;
Vector operator +(Vector A, Vector B){
	return Vector(A.x+B.x, A.y+B.y);
}
Vector operator -(Vector A, Vector B){
	return Vector(A.x-B.x, A.y-B.y);
}
Vector operator /(Vector A, TYPE X){
	return Vector(A.x/X, A.y/X);
}
Vector operator *(Vector A, TYPE X){
	return Vector(A.x*X, A.y*X);
}
TYPE dot(Vector A, Vector B){
	return A.x*B.x + A.y*B.y;
}
TYPE cross(Vector A, Vector B){
	return A.x*B.y - A.y*B.x;
}
double len(Vector A){
	return sqrt(dot(A, A));
}
double angle(Vector A, Vector B){
	return acos((double)dot(A, B) / len(A) / len(B));
}
const double t = acos(-1) / 2;
const double eps = 1e-10;
int dcmp(double x){
	if(fabs(x) < eps)
		return 0;
	return x > 0 ? 1 : -1;
}
int main(){
	int n;
	Vector v[500];
	while(scanf("%d", &n), n){
		for(int i = 0; i < n; i++)
			scanf("%d%d", &v[i].x, &v[i].y);
		int ans = 0;
		for(int i = 0; i < n-2; i++)
			for(int j = i+1; j < n-1; j++)
				for(int k = j+1; k < n; k++){
					Vector A = v[i], B = v[j], C = v[k];
					if(angle(C-A, C-B) < t && angle(B-A, B-C) < t && angle(A-B, A-C) < t)
						ans++;
				}
		printf("%d\n", ans);
	}
	return 0;
}
