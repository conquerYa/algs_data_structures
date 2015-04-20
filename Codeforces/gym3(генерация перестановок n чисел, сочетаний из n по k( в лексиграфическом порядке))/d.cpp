#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>
#include <string>
#include <fstream>
#include <stack>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;


void comb(int N, int K)
{
	std::string bitmask(K, 1); // K leading 1's
	bitmask.resize(N, 0); // N-K trailing 0's

	// print integers and permute bitmask
	do {
		for (int i = 0; i < N; ++i) // [0..N-1] integers
		{
			if (bitmask[i]) std::cout << i+1<<" ";
		}
		std::cout << std::endl;
	} while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}
int main(){
	//freopen("perm.in", "r", stdin);
	//freopen("perm.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	comb(n, k);
	return 0;
}