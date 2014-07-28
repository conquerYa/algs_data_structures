/*
The number is called perfect if it is equal to the sum of all its divisors less than himself. Required to find all the perfect numbers from M to N.
(1 <= M <= N <= 5*10^18)
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<long long> perf(int n);
int main(){
	long long a, b;
	cin >> a >> b;
	bool none = true;
	vector<long long> t = perf(35);
	for (long long x : t){
		if ((x >= a) && (x <= b)){
			cout << x << "\n";
			none = false;
		}
	}
	if (none){
		cout << "Absent" << "\n";
	}
	system("pause");
	return 0;
}

vector<long long> perf(int n){
	vector<char> prime(n + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= n; ++i)
	if (prime[i])
	if (i * 1ll * i <= n)
	for (int j = i*i; j <= n; j += i)
		prime[j] = false;

	vector<int> primes;
	for (int i = 0; i < prime.size(); i++){
		if (prime[i])
			primes.push_back(i);
	}

	vector<long long> perf;
	for (int x : primes){
		perf.push_back(pow(2, (x - 1))*(pow(2, x) - 1));
	}
	return perf;
}


