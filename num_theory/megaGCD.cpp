/*
required to find gcd of n numbers
*/

#include <iostream>
using namespace std;
int gcd(int a, int b);
int main() {
	int n;
	cin >> n;
	int *a = new int[n];
	int *l = new int[n];
	for(int i =0;i<n;i++){
		cin >>a[i];
	}
	l[0] = a[0];
	for(int i = 1;i<n;i++){
		l[i] = gcd(l[i-1],a[i]);
	}
	cout << l[n-1];
	return 0;
}

int gcd(int a, int b){
	return b>0?gcd(b,a%b):a;
}
