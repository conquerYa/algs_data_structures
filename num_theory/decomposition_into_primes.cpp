#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int i = 2;
	while (i <= sqrt(n))
	if (!(n%i)){
		cout << i;
		n /= i;
		if (n > 1) cout << "*";
	}
	else 
		i++;
	if (n > 1) cout << n;
	system("pause");
	return 0;
}

