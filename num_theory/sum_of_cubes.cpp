/*
required to find 2 integers, which sum of cubes is equal n
*/

#include <iostream>
using namespace std;
#include <cmath>
int main(){
	int n;
	cin >> n;
	bool t = true;
	for (int i = 1; i <= pow(n, 1/3); i++){
		for (int j = 0; j <= i; j++){
			if ((i*i*i + j*j*j) == n){
				cout << i << " " << j;
				i = j = n;
				t = false;
			}
		}
	}
	if (t)
		cout << "impossible";
	//system("pause");
	return 0;
}
