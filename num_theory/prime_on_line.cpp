/*
required to find all prime numbers on line (a,b)
*/

#include <iostream>
using namespace std;

bool isPrime(int n);
void print(int a, int b);
int main(){
	int a, b;
	cin >> a >> b;
	print(a, b);
	system("pause");
	return 0;
}


bool isPrime(int n){
	if (!(n % 2) && n>2 || n<2) return false;
	for (int i = 3; i < sqrt(n); i += 2){
		if (!(n%i)) return false;
	}
	return true;
}

void print(int a, int b){
	bool none = true;
	for (int i = a; i <= b; i++){
		if (isPrime(i)){
			cout << i << " ";
			none = false;
		}
	}
	if (none)
		cout << "Absent" << "\n";
}
