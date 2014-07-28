/*
required to find all prime divisors of n
*/
#include <iostream>
using namespace std;
#include <cmath>
bool isPrime(int n);
int main(){
	int n;
	cin >> n;
	if (!(n % 2))
		cout << 2 << " ";
	for (int i = 3; i <= n; i += 2){
		if (isPrime(i) && !(n%i))
			cout << i << " ";
	}
	//system("pause");
	return 0;
}

bool isPrime(int n){
	if (!(n % 2) && n>2 || n<2) return false;
	for (int i = 3; i <= sqrt(n); i += 2){
		if (!(n%i)) return false;
	}
	return true;
}
