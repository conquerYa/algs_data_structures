/*
Goldbach's conjecture:
Every even integer greater than 2 can be expressed as the sum of two primes.
*/


#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n);

int main(){
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++){
		if (isPrime(i) && isPrime(n - i)){
			cout << i << " " << (n - i);
			break;
		}
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
