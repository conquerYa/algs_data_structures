#include "iostream"
#include "cmath"
using namespace std;
int main()
{
	int p;
	int g;//g<p
	int x;//private key   x<p
	cout << "Enter p,g,x"<<endl;
	cin >> p >> g >> x;
	int y = (int)pow(g,x) % p;//public key
	cout << "y:(public) " << y<<endl;
	int k;//mod(k,p-1) = 1; 1<k<p-1
	int m;
	cout << "Enter k,m"<<endl;
	cin >> k >> m;
	int a = (int)pow(g, k) % p;
	int b = (int)pow(y, k)*m % p; 
	cout << "a: " << a << " b: " << b << endl;
	cout << (int)pow(a, x) <<"*m%"<<p<<" = " << b%p << endl;
	system("pause");
	return 0;
}

