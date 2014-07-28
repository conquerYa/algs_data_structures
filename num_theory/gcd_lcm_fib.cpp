#include <iostream>
using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);
int fib(int n);

int main(){
	int a, b, n;
	cin >> n;
	//cin >> a >> b;
	//cout << gcd(a,b); //íîä
	//cout << lcm(a, b); //íîê
	//cout << fib(n);
	system("pause");
	return 0;
}

int gcd(int a, int b) {
	return b>0?gcd(b, a%b):a;
}
int lcm(int a, int b) {
	return a*b/gcd(a,b);
}
int fib(int n){
	int *f = new int[n];
	f[0] = f[1] = 1;
	for (int i = 2; i < n; i++){
		f[i] = f[i - 2] + f[i - 1];
	}
	return f[n - 1];
}
