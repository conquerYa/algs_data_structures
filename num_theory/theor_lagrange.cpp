/*
Lagrange's four-square theorem states that any natural number can be represented as the sum of four integer squares
p = a_0^2 + a_1^2 + a_2^2 + a_3^2 
where the four numbers a_0, a_1, a_2, a_3 are integers.
*/
#include <iostream>
using namespace std;
#include <cmath>
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= sqrt(n); i++){
		for (int j = 0; j <= i; j++){
			for (int k = 0; k <= j; k++){
				for (int c = 0; c <= k; c++){
					if ((i*i + j*j + k*k + c*c)==n){
						cout << i << " ";
						if (j)
							cout << j << " ";
						if (k)
							cout << k << " ";
						if (c)
							cout << c;
						i = j = k = c = n;
					}
				}
			}
		}
	}
	//system("pause");
	return 0;
}
