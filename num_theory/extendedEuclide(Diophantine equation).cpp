/*
required to find any solution of Diophantine linear equation
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int gcd(int a, int b, int &x, int &y);
int main(){
	int a, b, c;
	int x, y;
	cin >> a >> b >> c;
	int g = gcd(abs(a), abs(b), x, y);
	if (c%g)
		cout << "Impossible";
	else{
		x *= c / g;
		y *= c / g;
		if (a < 0) x *= -1;
		if (b < 0) y *= -1;
		cout << g << " " << x << " " << y;
	}
	//system("pause");
	return 0;
}

/*
Extended Euclide algorithm
*/
int gcd(int a, int b, int &x, int &y){
	if (!a){ x = 0; y = 1; return b; }
	int x1, y1;
	int d = gcd(b%a, a, x1, y1);
	x = y1 - (b / a)*x1;
	y = x1;
	return d;
}