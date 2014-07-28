#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n);

int main(){
	int n;
	cin >> n;
	if (isPrime(n))
		cout << "prime";
	else
		cout << "composite";
	//system("pause");
	return 0;
}

bool isPrime(int n){
	if (!(n % 2) && n > 2 || n < 2) return false;
	for (int i = 3; i <= sqrt(n); i += 2){
		if (!(n%i))
			return false;
	}
	return true;
}

